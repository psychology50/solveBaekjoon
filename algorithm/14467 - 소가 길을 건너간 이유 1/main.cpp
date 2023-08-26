#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int cow[11];
    memset(cow, -1, sizeof(cow));

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int cowNum, pos; cin >> cowNum >> pos;
        if (cow[cowNum] == -1) cow[cowNum] = pos;
        else if (cow[cowNum] != pos) {
            cow[cowNum] = pos;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}