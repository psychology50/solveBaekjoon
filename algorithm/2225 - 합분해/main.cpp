#include <iostream>
#include <cmath>

#define MOD 1000000000

using namespace std;

int n, k;

int cache[205][205] = {0, };

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
   
    for (int i=1; i<=k; ++i) cache[0][i] = 1;
    for (int i=1; i<=n; ++i) for(int j=0; j<=k; ++j) {
        cache[i][j] = (cache[i-1][j] + cache[i][j-1]) % MOD;
    }

    cout << cache[n][k] << "\n";
    
    return 0;
}