#include <iostream>
#include <algorithm>
#include <cstring>

#define endl "\n"
using namespace std;

int enemy[20005];
int cache[10005][4];

int operation() {

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        memset(enemy, 0, sizeof(enemy));
        memset(cache, 0, sizeof(cache));
        int n, w; cin >> n >> w;

        for (int i=0; i < 2*n; i++) cin >> enemy[i];
        // cout << operation(0, 0, 0, n, w) << endl;
    }

    return 0; 
}