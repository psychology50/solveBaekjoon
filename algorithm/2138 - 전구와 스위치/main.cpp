#include <iostream>
#include <string>

#define MAX 100001

using namespace std;
int n;

void change(string& pre, int idx) {
    for (int i=idx-1; i<=idx+1; ++i) {
        if (i < 0 || i >= pre.size()) continue;
        pre[i] = (pre[i] == '0') ? '1' : '0';
    }
}

int check(string pre, string pos, int n, bool state) {
    int cnt = 0;

    if (state) {
        change(pre, 0);
        ++cnt;
    }

    for (int i = 1; i < n; ++i) {
        if (pre[i-1] != pos[i-1]) {
            change(pre, i);
            ++cnt;
        }
    }
    return (pre == pos) ? cnt : MAX;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    string pre, pos;
    cin >> pre >> pos;
    int res = min(check(pre, pos, n, false), check(pre, pos, n, true));
    cout << ((res == MAX) ? -1 : res);
    
    return 0;
}