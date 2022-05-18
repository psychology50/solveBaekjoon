#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) { // 전형적인 위상 정렬 문제
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;

    vector<int> graph[10001];
    int* indegree = new int[n+1];
    int* cost = new int[n+1];
    int result[10001];
    int t, m;

    for (int i=0; i < n+1; i++) {
        indegree[i] = 0;
        cost[i] = 0;
        result[i] = 0;
    }

    for (int i = 1; i < n+1; i++) {
        cin >> t >> m;

        cost[i] = t;
        for (int j = 0; j < m; j++) {
            int node;
            cin >> node;
            graph[node].push_back(i);
            indegree[i]++;
        }
    }

    priority_queue<int> queue;

    for (int i = 1; i < n+1; i++) {
        if (indegree[i] == 0) {
            queue.push(i);
            result[i] = cost[i];
        }
    }

    int tmp;
    while (!queue.empty()) {
        tmp = queue.top();
        queue.pop();
        for (auto i : graph[tmp]) {
            indegree[i]--;
            if (indegree[i] == 0) {
                queue.push(i);
            }
            if (result[i] < result[tmp] + cost[i]) {
                result[i] = result[tmp] + cost[i];
            }
        }
    }

    sort(result, result + n + 1);
    cout << result[n];

    return 0;
}