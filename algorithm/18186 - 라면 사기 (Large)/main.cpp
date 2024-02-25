#include <bits/stdc++.h>

#define MAX 1000005

using namespace std;
using ll = long long;
ll v[MAX];
ll ret = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, b, c; cin >> n >> b >> c;
    if (b < c) c = b; // 따로 사는 게 이득
    
    for (int i = 0; i < n; ++i) cin >> v[i];
    
    ll tmp = 0;
    for (int i=0; i<n; ++i) {
        if (v[i+1] > v[i+2]) {
            // 3번 째 공장 수요가 적은 경우, 앞에서 최대로 구매하고 이동
            tmp = min(v[i], v[i+1] - v[i+2]);
            ret += (b+c)*tmp;
            v[i] -= tmp, v[i+1] -= tmp;

            tmp = min(v[i], min(v[i+1], v[i+2]));
            ret += (b+2*c)*tmp;
            v[i] -= tmp, v[i+1] -= tmp, v[i+2] -= tmp;
        } else {
            // 3번 째 공장이랑 최대한 함께 구매
            tmp = min(v[i], min(v[i+1], v[i+2]));
            ret += (b+2*c)*tmp;
            v[i] -= tmp, v[i+1] -= tmp, v[i+2] -= tmp;

            tmp = min(v[i], v[i+1]);
            ret += (b+c)*tmp;
            v[i] -= tmp, v[i+1] -= tmp;
        }
        ret += b * v[i]; // 부족한 분량 구매
    }
    cout << ret;

    return 0;
}