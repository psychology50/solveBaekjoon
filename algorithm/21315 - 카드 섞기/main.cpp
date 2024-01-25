#include <iostream>
#include <cmath>

#define MAX 1001

using namespace std;
int n;
int start[MAX];
int target[MAX];

bool cmp(const int (&a)[MAX]) {
    for (int i = 0; i < n; ++i) if (a[i] != target[i]) return false;
    return true;
}

void mix(int range, int cnt) {
    int tmp[MAX];

    int idx = -1;
    for (int i=range-cnt; i<range; ++i) {
        tmp[++idx] = start[i];
        start[i] = 0;
    }
    for (int i=0; i<n; ++i) {
        if (start[i] != 0) tmp[++idx] = start[i];
        start[i] = tmp[i];
    }
}

void match(int k) {
    int range = n;

    for (int i = 1; i <= k+1; ++i) {
        int cnt = pow(2, k-i+1);
        mix(range, cnt);
        range = cnt;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i=0; i<n; ++i) cin >> target[i];

    for (int k1 = 1; pow(2, k1) <= n; ++k1) for (int k2 = 1; pow(2, k2) <= n; ++k2) {
        for (int i = 0; i < n; ++i) start[i] = i+1; 
        
        match(k1);
        match(k2);

        if (cmp(start)) {
            cout << k1 << " " << k2;
            return 0;
        }
    }

    return 0;
}