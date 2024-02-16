#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num; pq.push(num);
    }

    int cnt = 0;
    while (pq.size() != 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        cnt += a + b;
        pq.push(a+b);
    }
    cout << cnt;

    return 0;
}