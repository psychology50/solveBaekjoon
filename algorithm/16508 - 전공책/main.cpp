#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 987654321

using namespace std;
typedef struct Book {
    int cost;
    string name;
} Book;

string target;
int n;
vector<Book> books;
int cnt[30], selected[30];
int ret = MAX;

bool isValid() {
    for (int i=0; i<26; ++i) if (cnt[i] > selected[i]) return false;
    return true;
}

void dfs(int idx, int total) {
    if (idx == n) {
        if (isValid()) ret = min(ret, total);
        return ;
    }

    for (int i = 0; i < books[idx].name.length(); ++i) ++selected[books[idx].name[i] - 'A'];
    dfs(idx + 1, total + books[idx].cost);
    for (int i = 0; i < books[idx].name.length(); ++i) --selected[books[idx].name[i] - 'A'];
    dfs(idx + 1, total);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> target >> n; books.resize(n);
    for (int i=0; i<target.length(); ++i) ++cnt[target[i] - 'A'];
    for (int i = 0; i < n; ++i) cin >> books[i].cost >> books[i].name;
    dfs(0, 0);
    cout << ((ret != MAX) ? ret : -1);

    return 0;
}