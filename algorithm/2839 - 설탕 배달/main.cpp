#include <iostream>
#include <algorithm>

#define MAX 5001

using namespace std;
int n;
int cache[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cache[3] = cache[5] = 1;

    for (int i = 6; i <= n; ++i) {
        if (cache[i - 3]) cache[i] = cache[i - 3] + 1;

        if (cache[i - 5]) cache[i] = (cache[i]) ? min(cache[i], cache[i-5]+1) : cache[i-5] + 1;
    }
    cout << (cache[n] == 0 ? -1 : cache[n]) << "\n";

    return 0;
}