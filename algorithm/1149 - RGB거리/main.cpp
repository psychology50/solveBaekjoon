#include <iostream>
#include <cmath>

#define MAX 987654321

using namespace std;

int n;
int cost[1001][3];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i=1; i<=n; ++i) {
        int R, G, B; cin >> R >> G >> B;
        cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + R;
        cost[i][1] = min(cost[i-1][0], cost[i-1][2]) + G;
        cost[i][2] = min(cost[i-1][0], cost[i-1][1]) + B;
    }

    cout << min(cost[n][0], min(cost[n][1], cost[n][2])) << "\n";

    return 0;
}