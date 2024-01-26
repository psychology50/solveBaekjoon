#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int n, m;
string king;
set<string> people;
map<string, int> indegree;
map<string, ll> cost;
map<string, vector<string>> graph;
ll tmp = 1LL << 52;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> king;

    string c, p1, p2;
    cost[king] = tmp;
    for (int i = 0; i < n; ++i) {
        cin >> c >> p1 >> p2;
        graph[p1].push_back(c); 
        graph[p2].push_back(c);
        indegree[c] += 2;
        people.insert(c), people.insert(p1), people.insert(p2);
    }

    queue<string> q;
    for (auto i : people) if (indegree[i] == 0) q.push(i);

    while (!q.empty()) {
        string now = q.front(); q.pop();

        for (auto nxt : graph[now]) {
            if (--indegree[nxt] == 0) q.push(nxt);
            cost[nxt] += cost[now] * 0.5;
        }
    }

    tmp = 0;
    string ans, name;
    for (int i=0; i<m; ++i) {
        cin >> name;
        if (cost[name] > tmp) tmp = cost[name], ans=name;
    }

    cout << ans;

    return 0;
}