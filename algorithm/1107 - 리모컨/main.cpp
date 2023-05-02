#include <iostream>
#include <vector>
#include <string>

#define MAX 1000000

using namespace std;

vector<int> broken;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;

    // 리모콘 0~9, +, - 버튼
    // 이동하려는 채널 N (0 <= N <= 500,000) 
    // 고장난 버튼 수 M (0 <= M <= 10)

    for (int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        broken.push_back(tmp);
    }

    // 1. +, - 버튼만으로 이동하는 경우
    int ans = abs(n - 100);

    // 2. 숫자 버튼을 누르고 +, - 버튼으로 이동하는 경우
    for (int ch=0; ch < MAX; ch++) {
        string now = to_string(ch);
        bool flag = false;
        for (int digit = 0; digit < now.size(); digit++) {
            for (int idx = 0; idx < broken.size(); idx++) if (now[digit]-'0' == broken[idx]) {
                flag = true;
                break;
            }
            if (flag) break;
        }
        if (!flag) {
            ans = min(ans, (int)now.size() + abs(n - ch));
        }
    }

    cout << ans << "\n";
    return 0;
}