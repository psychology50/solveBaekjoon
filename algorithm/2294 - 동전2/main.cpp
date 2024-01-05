#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 987654321

using namespace std;

int n, k;
int cache[100001];
vector<int> coins;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    
    for (int i=0; i<=k; ++i) cache[i] = MAX;
    for (int i=0; i<n; ++i) {
        int coin; cin >> coin;
        coins.push_back(coin);
        cache[coin] = 1;
    }

    for (int i=0; i<n; ++i) {
        int& coin = coins[i];
        if (coin > 10000) continue;
        for (int j=coin; j<=k; ++j) {
            cache[j] = min(cache[j], cache[j - coin] + 1);
        }
    }
    
    cout << (cache[k] == MAX ? -1 : cache[k]);
    return 0;
}