#include <iostream>
#include <cstring>

#define MOD 1000000007
#define MAX 1516

using namespace std;
int n;

// 15의 배수
// 3과 5의 공배수.
// 1과 5로 이루어진 수이므로 마지막 자리는 5로 고정 (5의 배수는 0 또는 5이므로)
// cache[모든 자릿수 합을 3으로 나눈 나머지][숫자 길이] = 경우의 수
int cache[3][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    // 길이 2일 때, 
    // 15(-> 모든 자릿수 합 % 3 == 0) -> 15의 배수
    // 55(-> 모든 자릿수 합 % 3 == 1)

    // 길이 3일 때, 
    // 115(-> 모든 자릿수 합 % 3 == 1)
    // 515(-> 모든 자릿수 합 % 3 == 2)
    // 155(-> 모든 자릿수 합 % 3 == 2) 
    // 555(-> 모든 자릿수 합 % 3 == 0) -> 15의 배수

    // 길이 2의 55(나머지 1)에서 5(나머지 2)를 더하면 길이 3의 515(나머지 2)가 된다.
    // 길이 2의 15(나머지 0)에서 5(나머지 2)를 
    // 길이 2의 15(나머지 0)에서 1(나머지 1)를 
    cache[0][2] = cache[1][2] = 1;

    for (int i=3; i<=n; ++i) {
        cache[0][i] = (cache[1][i-1] + cache[2][i-1]) % MOD;
        cache[1][i] = (cache[0][i-1] + cache[2][i-1]) % MOD;
        cache[2][i] = (cache[0][i-1] + cache[1][i-1]) % MOD;
    }

    cout << cache[0][n];
    return 0;
}