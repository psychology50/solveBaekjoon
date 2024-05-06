#include <string>
#include <vector>
#include <queue>

#define MAX 200

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
bool visited[MAX];
int ret;

void bfs(const int& start, vvi& computers) {
    queue<int> q; q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (int nxt=0; nxt<computers[cur].size(); ++nxt) {
            if (nxt == cur || computers[cur][nxt] == 0 || visited[nxt]) continue;
            visited[nxt] = true;
            q.push(nxt);
        }
    }
    ++ret;
}

int solution(int n, vvi computers) {
    for (int i=0; i<n; ++i) {
        if (visited[i]) continue;
        bfs(i, computers);
    }
    return ret;
}