#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstdio>
#include <vector>

#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;

    for (int i=0; i<n; i++) {
        int nbr; cin >> nbr;
        if (max_q.size() == min_q.size()) {
            max_q.push(nbr);
        } else {
            min_q.push(nbr);
        }
        if (!max_q.empty() && !min_q.empty() && (max_q.top() > min_q.top())) {
            int max, min;
            max = max_q.top(); min = min_q.top();
            max_q.pop(); min_q.pop();
            swap(max, min);
            max_q.push(max); min_q.push(min);
        }
        cout << max_q.top() << endl;
    }

    return 0;
}