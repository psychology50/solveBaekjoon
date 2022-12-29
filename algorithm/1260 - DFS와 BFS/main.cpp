#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;

vector<int> graph[10001];
bool visited[10001] = {false};

int dfs(int N, int M, int V) {
    visited[V] = true;
    cout << V << " ";
    for (auto i : graph[V]) {
        if (!visited[i]) {
            dfs(N, M, i);
        }
    }

    return 0;
}

int bfs(int N, int M, int V) {
    bool visited[10001] = {false};
    queue<int> q; q.push(V);
    
    while (!q.empty()) {
        int now = q.front(); q.pop();
        cout << now << " ";
        if (!visited[now])
            for (auto v : graph[now]) {
                q.push(v);
                visited[v] = true;
            }
    }

    return 0;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M, V; cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int v, w; cin >> v >> w;
        graph[v].push_back(w);
    }

    dfs(N, M, V);
    cout << endl;
    bfs(N, M, V);

    return 0;
}