#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int n, k, s;

void init();
void bfs(int, vector<bool>&, queue<int>&);
int adj[410][410];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();

    queue<int> q;
    for (int history=1; history<=n; ++history) {
        vector<bool> visited; visited.resize(n+1);
        for (int item=1; item<=n; ++item)
            if (adj[history][item] == -1)
                q.push(item);
        bfs(history, visited, q);
    }

    cin >> s;
    for (int i=0; i<s; ++i) {
        int a, b; cin >> a >> b;
        cout << adj[a][b] << "\n";
    }
}

void init() {
    cin >> n >> k;
    
    for (int i=0; i<k; ++i) {
        int early, later; cin >> early >> later;
        adj[early][later] = -1;
        adj[later][early] = 1;
    }
}

void bfs(int target, vector<bool> &visited, queue<int> &q) {
    while (q.size() > 0) {
        int now = q.front(); q.pop();

        if (visited[now]) continue;
        visited[now] = true;

        if (adj[target][now] != -1) {
            adj[target][now] = -1;
            adj[now][target] = 1;
        }

        for (int item=1; item<=n; ++item)
            if (!visited[item] && adj[now][item] == -1)
                q.push(item);
    }
}