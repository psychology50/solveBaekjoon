#include <iostream>
#include <vector>

#define MAX 21
#define endl "\n"

using namespace std;

struct STUDENT {
    int num;
    int favor[4];
};

int res[MAX][MAX];
STUDENT arr[MAX * MAX];

int vector[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void go(int n, int idx) {
    for (int y=0; y<n; y++) for (int x=0; x<n; x++) {
        if (res[y][x] != 0) continue;

        for (auto v : arr[idx].favor) {
            cout << v << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for(int i=0; i < n*n; i++) {
        cin >> arr[i].num;
        for(int j=0; j < 4; j++) cin >> arr[i].favor[j];
    }

    for(int idx=0; idx<n; idx++) go(n, idx);

    return 0;
}