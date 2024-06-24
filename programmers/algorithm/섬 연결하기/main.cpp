#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

int parent[101];

int getParent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}

bool cmp(vi& a, vi& b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    for (int i=0; i<n; ++i) parent[i] = i;
    
    sort(costs.begin(), costs.end(), cmp);
    
    int ret = 0;
    for (vi& cost: costs) {
        int s = getParent(cost[0]), e = getParent(cost[1]);
        int w = cost[2];
        
        if (s != e) {
            if (s > e) swap(s, e);
            ret += w;
            parent[e] = s;
        }
    }
    return ret;
}