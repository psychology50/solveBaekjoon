#include <bits/stdc++.h>

#define INF 3e10

using namespace std;
using ll = long long;

int n;
vector<int> input;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; input.resize(n);
    for (int& i : input) cin >> i;
    sort(input.begin(), input.end());

    ll sum = INF;
    int ret[3];
    for (int l=0; l<n-2; ++l) {
        int m = l+1, r = n-1;

        ll first = input[l], second, third;
        while (m < r) {
            second = (ll)input[m], third = (ll)input[r];

            if (abs(sum) > abs(first + second + third)) {
                sum = first + second + third;
                ret[0] = first, ret[1] = second, ret[2] = third;
            }

            if (sum >= 0) --r;
            else ++m;
        }
    }

    sort(ret, ret+3);
    cout << ret[0] << " " << ret[1] << " " << ret[2];

    return 0;
}