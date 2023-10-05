#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    vector<int> dp(31, 0);
    dp[0] = 3;
    dp[1] = 11;
    int tmp = 0;

    if (N > 2) {
        for (int i = 2; i < N / 2; ++i) {
            tmp += dp[i - 2] * 2;
            dp[i] = dp[i - 1] * 3 + 2 + tmp;
        }
    }

    cout << (N % 2 == 0 ? dp[N / 2 - 1] : 0) << endl;

    return 0;
}