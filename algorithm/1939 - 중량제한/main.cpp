#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m;
int source, sink;
int maxW;
vector<vector<pii>> islands;
vector<bool> visited;

void findMaxWeight(int cur, int target) {
    for (int island=0; island<islands[cur].size(); ++island) {
        int nxt = islands[cur][island].first;
        int w = islands[cur][island].second;
        if (w < target || visited[nxt]) continue;
        visited[nxt] = true;
        findMaxWeight(nxt, target);
    }
}

int binarySearch(int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        visited.clear();
        visited.resize(n+1, false);
        visited[source] = true;
        findMaxWeight(source, mid);
        if (visited[sink]) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    islands.resize(n+1, vector<pii>());
    for (int i=0; i<m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        islands[u].push_back({v, w});
        islands[v].push_back({u, w});
        maxW = max(maxW, w);
    }
    cin >> source >> sink;
    cout << binarySearch(0, maxW);

    return 0;
}