#include <iostream>

using namespace std;
typedef long long ll;

int n;
int numbers[101];
ll cache[101][21];

ll dfs(int now, int depth) {
    if (depth == n-2) {
        return (now == numbers[n-1]) ? 1 : 0;
    }

    ll& res = cache[depth][now];
    if (res != 0) return res;

    if (now + numbers[depth] <= 20) 
        res += dfs(now + numbers[depth], depth + 1);
    if (now - numbers[depth] >= 0)
        res += dfs(now - numbers[depth], depth + 1);
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) cin >> numbers[i];

    cout << dfs(numbers[0], 0);

    return 0;
}