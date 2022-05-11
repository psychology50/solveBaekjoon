#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using p = pair<int, int>;
#define INF 2147483647

void dijkstra(int depth, vector<p> *graph, vector<int> &distance) {
    distance[depth] = 0;
    priority_queue<p> q;
    q.push({distance[depth], depth});

    while (!q.empty()) {
        int dist = q.top().first;
        int current = q.top().second;
        q.pop();

        if (distance[current] < dist) continue;

        for (int idx=0; idx < graph[current].size(); idx++) {
            int nxt = graph[current][idx].first;
            int nxt_dist = graph[current][idx].second + dist;

            if (nxt_dist < distance[nxt]) {
                distance[nxt] = nxt_dist;
                q.push({nxt_dist, nxt});
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;

    vector<p> graph[1001];
    vector<int> distance(1001, INF);

    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start, graph, distance);

    cout << distance[end];

    return 0;
}