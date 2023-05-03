#include <iostream>
#include <vector>

#define ll long long
#define MAX 51
#define endl "\n"

using namespace std;

double building[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // 빌딩의 수 N (0 < N <= 50)
    // 빌딩의 높이 (1 <= 높이 <= 1,000,000,000)
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> building[i];

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    } else if (n == 2) {
        cout << 1 << endl;
        return 0;
    } 

    int ans = 0;
    for (int now=0; now<n; now++) {
        int cnt = 0;
        for (int target=0; target<n; target++) {
            if (now == target) continue;

            double slope = double(abs(building[now] - building[target])) / abs(now - target);
            bool flag = false;

            if (building[now] > building[target])
                slope *= -1;
            if (target < now) {
                for (int idx = now-1; idx>target; idx--) {
                    if (slope * abs(now - idx) + building[now] <= building[idx]) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) cnt++;
            } else {
                for (int idx = now+1; idx<target; idx++) {
                    if (slope * abs(now - idx) + building[now] <= building[idx]) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}