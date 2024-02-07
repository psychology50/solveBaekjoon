#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 55

using namespace std;

typedef struct Node {
    int u, v, w;
} Node;
vector<Node> graph;

int n;
string alphabet = "0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int node[MAX];

int F(int& a) {
    if (node[a] == a) return a;
    return node[a] = F(node[a]);
}

bool U(int a, int b) {
    a = F(a);
    b = F(b);

    if (a == b) return false;

    if (a > b) node[a] = b;
    else node[b] = a;
    return true;
}

bool cmp(Node& a, Node& b) {
    return a.w < b.w;
}

int calcWeight(char c) {
    for (int i=0; i<alphabet.size(); ++i) {
        if (alphabet[i] == c) return i; 
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    char c; int w, total=0;
    for (int source = 0; source < n; ++source) {
        for (int sink = 0; sink < n; ++sink) {
            cin >> c; w = calcWeight(c);
            if (w == 0) continue;
            total += w;
            if (source == sink) continue;
            graph.push_back({source, sink, w});
        }
        node[source] = source;
    }
    sort(graph.begin(), graph.end(), cmp);

    int cnt=0, sum=0;
    for (Node& node : graph) {
        if (U(node.u, node.v)) {
            sum += node.w;
            if (++cnt == n-1) break;
        }
    }

    if (cnt < n-1) {
        cout << -1;
    } else {
        cout << total - sum;
    }
    return 0;
}