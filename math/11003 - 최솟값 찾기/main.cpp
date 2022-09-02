#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, L, t; cin >> N >> L;
    deque<pll> q;
    pll data;

    for (int i=1; i<=N; i++) {
        data.first = i; cin >> data.second;
        while (!q.empty() && data.second <= q.back().second)
            q.pop_back();
        q.push_back(data);
        if (q.front().first <= i-L)
            q.pop_front();
        cout << q.front().second << ' ';
    }

    return 0;
}