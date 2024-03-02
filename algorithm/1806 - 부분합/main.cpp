#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, s; cin >> n >> s;
    vector<int> numbers; numbers.resize(n);
    for (int i = 0; i < n; ++i) cin >> numbers[i];

    int start = 0, end = 0, sum = numbers[0], ret = n + 1;
    while (start <= end && end < n) {
        if (sum < s) {
            sum += numbers[++end];
        } else {
            ret = min(ret, end - start + 1);
            sum -= numbers[start++];
        }
    }

    cout << ((ret != n+1) ? ret : 0);

    return 0;
}