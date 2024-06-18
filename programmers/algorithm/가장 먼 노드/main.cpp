#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX 20001

using namespace std;
using vi = vector<int>;

int N;
vi graph[MAX];
int dist[MAX];

void dijkstra() {
    queue<int> q; q.push(1);
    vector<bool> visited(N+1);
    visited[1] = true;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (int i=0; i<graph[cur].size(); ++i) {
            int nxt = graph[cur][i];
            if (!visited[nxt]) {
                visited[nxt] = true;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    N = n;
    for (vi& e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    dijkstra();
    int maxDist=0, cnt=0;
    for (int i=1; i<=n; ++i) {
        if (maxDist < dist[i]) {
            maxDist = dist[i]; cnt = 1;
        } else if (maxDist == dist[i]) {
            ++cnt;
        }
    }
    
    return cnt;
}