#include <iostream>

using namespace std;
typedef long long ll;

ll k;

ll f(ll x) { 
    if (x==1) return 0;
    ll i;
    for (i=1; i+i<x; i+=i);
    return !f(x-i);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k;

    cout << f(k);
    return 0;
}