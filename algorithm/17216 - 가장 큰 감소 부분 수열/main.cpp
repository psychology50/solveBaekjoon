#include <iostream>
#include <cmath>

using namespace std;
int n;
int cache[1001][2];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int seq[n];

    for (int now = 0; now < n; ++now) {
        cache[now][0] = 1;
        cin >> seq[now];
        cache[now][1] = seq[now];

        for (int pre=now; pre>=0; --pre) {
            if (seq[pre] > seq[now]) {
                cache[now][0] = max(cache[now][0], cache[pre][0] + 1);
                cache[now][1] = max(cache[now][1], seq[now] + cache[pre][1]);
            }
        }
    }

    int ans=0;
    for (int i=0; i<n; ++i) {
        ans = max(ans, cache[i][1]);
    }
    cout << ans;

    return 0;
}