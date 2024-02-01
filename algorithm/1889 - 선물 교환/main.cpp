#include <iostream>
#include <queue>
#include <vector>

#define MAX 200010

using namespace std;
int n;

int indegree[MAX];
int graph[MAX][2];
bool visited[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    int t1, t2;
    for (int i = 1; i <= n; ++i) {
        cin >> graph[i][0] >> graph[i][1];
        ++indegree[graph[i][0]]; ++indegree[graph[i][1]];
    }
    
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0 || indegree[i] == 1) {
            q.push(i);
            visited[i] = true;
        }
    }

    int cnt = q.size();
    while (!q.empty()) {
        int from = q.front(); q.pop();

        for (int i=0; i<2; ++i) {
            int to = graph[from][i];
            --indegree[to];
            graph[from][i] = -1;

            if ((indegree[to] == 0 || indegree[to] == 1) && !visited[to]) {
                visited[to] = true;
                q.push(to); ++cnt;
            }
        }
    }

    cout << n - cnt << "\n";
    for (int i = 0; i < n; ++i) if (graph[i][0] != -1) cout << i+1 << " ";

    return 0;
}