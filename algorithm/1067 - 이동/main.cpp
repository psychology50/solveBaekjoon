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
    // ===
    for (auto c : a) cout << c << " "; 
    cout <<endl; 
    // === //
    for (int i = 1, j = 0; i < n; i++) {
        for (int bit = n >> 1; !((j^=bit)&bit); bit >>=1);
        if (i < j) swap(a[i], a[j]);
    }
    // ===
    for (auto c : a) cout << c << " ";
    cout << endl;
    // === //
    
    for (int i=1; i<n; i<<=1) { // peroid
        double angle = (inv ? -1 : 1) * PI / i; // inv ? IDFT : DFT
        base w = {cos(angle), sin(angle)};
        for (int j=0; j<n; j += i << 1) {
            base th = {1, 0};
            for (int k=0; k < i; k++) {
                cout << "===== " <<"i: "<<i<<", j: "<< j<<", k: "<< k <<" => i+j+k = "<<i+j+k<<", j+k = "<<j+k<< " ===="<<endl;
                base tmp = a[i+j+k] * th;
                cout<<"a["<<i+j+k<<"] = "<<a[i+j+k]<<", a["<<j+k<<"] = "<<a[j+k]<<", th = "<<th<<", tmp = "<<tmp<<endl;
                a[i+j+k] = a[j+k] - tmp; // F(u + k) = Feven(u) - Fodd(u)W
                a[j+k] += tmp;
                cout << a[j+k] << ", " << a[i+j+k] << endl;
                th *= w; // 복소수 그래프 상에서 회전
            }
        }
    }
    if (inv) // IFFT
        for (int i=0; i<n; i++) 
            a[i] /= n;
}

vector<ll> multiply(vector<ll> &a, vector<ll> &b) {
    vector<base> A(a.begin(), a.end()), B(b.begin(), b.end());

    int n = 1; // 2의 거듭제곱 자릿수로 resize
    while (n < A.size() + B.size()) n <<= 1; // n = 16

    // FFT
    A.resize(n); fft(A, false);
    //
    for (auto t : A) cout << t << " ";
    cout<<endl<<endl;
    //
    B.resize(n); fft(B, false);
    //
    for (auto t : B) cout << t << " ";
    cout<<endl<<endl;
    //

    for (int i=0; i<n; i++) {
        cout << A[i] << " *= " << B[i] << " = " << A[i]*B[i] << endl;
        A[i] *= B[i];
    }
    cout<<endl<<endl;
    fft(A, true); // IFFT
    //
    for (auto t : A) cout << t << " ";
    cout<<endl<<endl;
    //

    vector<ll> res(n);
    for(int i=0; i<n; i++) res[i] = (ll)round(A[i].real()); // 실수부
    //
    for (auto t : res) cout << t << " ";
    cout<<endl<<endl;
    //
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
    for (ll v : res) {
        //
        cout << v << " ";
        //
        answer = max(answer, v);
    }
    cout << endl;
    cout << answer << endl;

    return 0;
}