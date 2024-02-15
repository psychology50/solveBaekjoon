#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;
int n;
int sticker[2][MAX], cache[2][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t; ++t;
    while (--t) {
        cin >> n;
        for (int i=0; i<2; ++i) for (int j=1; j<=n; ++j) cin >> sticker[i][j];
    
        cache[0][1] = sticker[0][1], cache[1][1] = sticker[1][1];

        for (int i=2; i<=n; ++i) {
            cache[0][i] = max(cache[1][i - 2], cache[1][i - 1]) + sticker[0][i];
            cache[1][i] = max(cache[0][i - 2], cache[0][i - 1]) + sticker[1][i];
        }

        cout << max(cache[0][n], cache[1][n]) << "\n"; 
    }
    
    return 0;
}