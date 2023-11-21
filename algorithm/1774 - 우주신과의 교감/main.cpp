#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define INF 2147483647

using namespace std;

typedef pair<int, int> pii;
typedef long double ld;
typedef struct Edge {
    int u, v;
    ld w;
} Edge;

int n, m;
vector<Edge> edges; 
vector<pii> godCoords;
int parent[1001];

void init();
int findParent(int);
void unionParent(int, int);
bool cmpParent(int, int);
ld makeMST();
ld calcDist(pii a, pii b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
bool cmp(Edge &a, Edge &b) {
    return a.w < b.w; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout.precision(2); cout.setf(ios::fixed);
    init();
    sort(edges.begin(), edges.end(), cmp);

    cout << makeMST() << "\n";
    
    return 0;
}

void init() {
    cin >> n >> m;
    for (int i=0, x, y; i<n; ++i) {
        cin >> x >> y;
        godCoords.push_back({y, x});
    }

    for (int i=0; i<=n; ++i) parent[i] = i;
    for (int i=0, u, v; i<m; ++i) {
        cin >> u >> v;
        unionParent(u-1, v-1);
    }

    for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
        if (cmpParent(i, j)) continue;
        edges.push_back({i, j, calcDist(godCoords[i], godCoords[j])});
    }
}

int findParent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool cmpParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    return (a == b) ? true : false;
}

ld makeMST() {
    ld answer = 0;

    for (int i=0; i<edges.size(); ++i) {
        if (cmpParent(edges[i].u, edges[i].v)) continue;

        answer += edges[i].w;
        unionParent(edges[i].u, edges[i].v);
    }
    return answer;
}