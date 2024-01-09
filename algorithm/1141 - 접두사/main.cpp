#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, string>> words;

bool compare(string& a, string& b) {
    for (int i = 0; i < a.length(); ++i)
        if (a[i] != b[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; words.resize(n);
    for (int i = 0; i < n; ++i) {
        string tmp; cin >> tmp;
        words[i] = make_pair(tmp.length(), tmp);
    }
    sort(words.begin(), words.end());

    int res = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = i + 1; j < n; ++j) {
            if (compare(words[i].second, words[j].second)) {
                flag = true;
            }
        }
        if (flag) ++res;
    }

    cout << n - res;

    return 0;
}