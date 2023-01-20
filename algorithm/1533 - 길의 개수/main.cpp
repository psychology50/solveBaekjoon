#include <iostream>
#include <vector>

#define MOD 1000003

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vvl;

int n, s, e, t; 

vvl matrix_multiple(vvl &matrix1, vvl &matrix2) {
    vvl tmp(n*5+1, vector<ll>(n*5+1, 0));
    for (int i=1; i<=n*5; i++) for (int j=1; j<=n*5; j++) for (int k=1; k<=n*5; k++) {
        tmp[i][j] += matrix1[i][k] * matrix2[k][j];
        tmp[i][j] %= MOD;
    }
    return tmp;
}

ll solve(vvl &cache1, vvl &cache2) {
    while(t > 0) {
        if (t % 2 == 1) {
            cache2 = matrix_multiple(cache1, cache2);
            // t -= 1;
        }
        cache1 = matrix_multiple(cache1, cache1);
        t /= 2;
    }

    return cache2[s * 5][e * 5];
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s >> e >> t;
    
    vvl cache1(n*5+1, vector<ll>(n*5+1, 0));
    vvl cache2(n*5+1, vector<ll>(n*5+1, 0));

    for (int i=0; i<n; i++) {
        string s; cin >> s;
        for (int j=0; j<n; j++) { // 연결 정보 갱신
            char c; c = s[j]; c -= '0';
            if (c != 0) {
                cache1[(i+1)*5][(j+1)*5 - (c-1)] = 1;
            }
        }
        for (int j=1; j<5; j++) { // 분리된 간선 연결
            cache1[i*5 + j][i*5 + j + 1] = 1;
        }
    }
    for (int i=1; i<=5*n; i++) { // 단위행렬
        cache2[i][i] = 1;
    }

    for (auto a : cache1) {
        for (auto b: a) {
            cout << b << " ";
        }
        cout << endl;
    }

    cout << solve(cache1, cache2);
    return 0;
}
