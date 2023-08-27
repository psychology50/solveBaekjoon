#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int n, m; 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
        
    vector<int> train(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int cmd; cin >> cmd;
        int trainNum, seatNum;
        if (cmd == 1) {
            cin >> trainNum >> seatNum;
            train[trainNum] |= (1 << (seatNum - 1));
        } else if (cmd == 2) {
            cin >> trainNum >> seatNum;
            train[trainNum] &= ~(1 << (seatNum - 1));
        } else if (cmd == 3) {
            cin >> trainNum;
            train[trainNum] <<= 1;
            train[trainNum] &= ((1 << 20) - 1);
        } else if (cmd == 4) {
            cin >> trainNum;
            train[trainNum] >>= 1;
        }
    }

    int cnt = 0;
    vector<bool> visited(1 << 20, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[train[i]]) {
            visited[train[i]] = true;
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}