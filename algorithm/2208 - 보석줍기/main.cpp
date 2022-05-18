#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    int cache[100001];
    int pickUp = 0, cost = 0;
    int min_value = 0, max_value = 0;
    for (int i=1; i<=n; i++) { // 1~n부터 계속 주운 값을 cache에 넣는다.
        cin >> pickUp;
        cost += pickUp;
        cache[i] = cost;
    }
    for (int i = m-1; i < n; i++) {
        cout << "\nidx = " << i << "\n";
        cout << "min_value = " << min_value << ", cache[" << i - (m-1) << "] = " << cache[i-(m-1)] << "\n";
        min_value = min(min_value, cache[i - (m-1)]);
        cout << "max_value = " << max_value << ", cache[" << i +1 << "] - min_value = " << cache[i+1] - min_value << "\n";
        max_value = max(max_value, cache[i + 1] - min_value);
    }
    cout << max_value;

    return 0;
}