#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n, target;
int dydx[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> target; 

    int map[n][n];

    int y = n/2, x = n/2;
    int flag = 0, now = 0;
    int end = pow(n, 2);
    int resY, resX;

    while (true) {
        if (now > end) break;

        int cnt = flag/2 + 1;
        int ahead = flag % 4;
        
        for (int i=0; i<cnt; ++i) {
            map[y][x] = ++now;

            if (now == target) {
                resY = y; resX = x;
            }

            y += dydx[ahead][0];
            x += dydx[ahead][1];
        }
        ++flag;
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << resY+1 << " " << resX+1;

    return 0;
}