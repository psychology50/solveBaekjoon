#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>

#define endl "\n"
#define ll long long

using namespace std;
typedef complex<double> base;

const double PI = acos(-1);

void fft(vector<base> &a, bool inv) {
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; i++) { // clause f sort (정확한 원리는 아직 이해 X)
        for (int bit = n >> 1; !((j^=bit)&bit); bit >>=1) // f_odd항과 f_even 분리
        if (i < j) swap(a[i], a[j]);
    }
    
    for (int i=1; i<n; i<<=1) {
        double angle = (inv ? -1 : 1) * PI / i; // inv ? IFFT : FFT
        base w = {cos(angle), sin(angle)}; // 감는 각도
        for (int j=0; j<n; j += i << 1) {
            base th = {1, 0};
            for (int k=0; k < i; k++) {
                base tmp = a[i+j+k] * th; // wH(u)
                a[i+j+k] = a[j+k] - tmp; // F(u) = G(u) - wH(u)
                a[j+k] += tmp; // F(u) = G(u) + wH(u)
                th *= w; // 복소수 그래프 상에서 회전
            }
        }
    }
    if (inv) // IFFT (수학적으로 증명됨.)
        for (int i=0; i<n; i++) 
            a[i] /= n;
}

vector<ll> multiply(vector<ll> &a, vector<ll> &b) {
    vector<base> A(a.begin(), a.end()), B(b.begin(), b.end());

    int n = 1; // 2의 거듭제곱 자릿수로 resize
    while (n < A.size() + B.size()) n <<= 1; // (n < A.size() || n < B.size()) => 오답. why? 

    // FFT
    A.resize(n); fft(A, false);
    B.resize(n); fft(B, false);

    for (int i=0; i<n; i++) A[i] *= B[i];
    fft(A, true); // IFFT

    vector<ll> res(n);
    for(int i=0; i<n; i++) res[i] = (ll)round(A[i].real()); // 실수부
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<ll> a(n*2), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i]; 
        a[i + n] = a[i];
    }
    for (int i=1; i <= n; i++) cin >> b[n - i];
    vector<ll> res = multiply(a, b);

    ll answer = 0;
    for (ll v : res) answer = max(answer, v);
    cout << answer << endl;

    return 0;
}