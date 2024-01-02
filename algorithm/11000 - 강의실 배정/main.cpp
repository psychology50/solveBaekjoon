#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> lectures;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    lectures.resize(n);
    for (int i=0; i<n; ++i) {
        cin >> lectures[i].first >> lectures[i].second;
    }

    sort(lectures.begin(), lectures.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(lectures[0].second);

    for (int i=1; i<n; ++i) {
        if (pq.top() <= lectures[i].first) pq.pop();
        pq.push(lectures[i].second);
    }

    cout << pq.size() << endl;
    return 0;
}