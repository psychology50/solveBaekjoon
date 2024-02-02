#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 101

using namespace std;
using pii = pair<int, int>;

int n, m;
vector<pii> adj[MAX];
int indegree[MAX], cnt[MAX];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int u, v, w;
    for(int i=0;i<m;++i){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        ++indegree[v];
    }

    vector<int> ans;
    queue<int> q; q.push(n);
    cnt[n]=1;

    while(!q.empty()){
        int cur=q.front(); q.pop();
        if(adj[cur].empty()){
            ans.push_back(cur);
        }

        for(auto& p : adj[cur]){
            int nxt = p.first, cost = p.second;
            cnt[nxt] += cnt[cur]*cost;

            if(--indegree[nxt]==0) q.push(nxt);
        }
    }

    sort(ans.begin(),ans.end());
    for(auto& a : ans) cout << a << " " << cnt[a] << "\n";
}