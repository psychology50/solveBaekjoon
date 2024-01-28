#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n;
vector<int> seq;
int res = 987654321;

void recur(vector<int> now, int cnt) {
    int l = -1, r = now.size();

    bool flag = true;
    while (++l < --r) {
        if (now[l] != now[r]) {
            now.insert(now.begin() + r + 1, now[l]);
            recur(now, cnt+1);
            now.erase(now.begin() + r + 1);

            now.insert(now.begin() + l, now[r]);
            recur(now, cnt+1);

            flag = false;
            break;
        }
    }

    if (flag) res = min(res, cnt);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    seq.resize(n);
    for (int i = 0; i < n; ++i) cin >> seq[i];

    recur(seq, 0);
    cout << res;

    return 0;
}