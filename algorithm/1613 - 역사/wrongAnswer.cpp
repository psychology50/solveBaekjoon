#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int n, k, s;

int getParent(int[], int);
void unionParent(int[], int, int);
int findParent(int[], int, int);

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    int histories[n+1];
    for (int node=0; node<n; ++node) histories[node] = node;

    for (int i=0; i<k; ++i) {
        int ealryHistory, laterHistory;
        cin >> ealryHistory >> laterHistory;
        unionParent(histories, ealryHistory, laterHistory);
    }

    cin >> s;
    for (int i=0; i<s; ++i) {
        int a, b; cin >> a >> b;
        cout << findParent(histories, a, b) << "\n";
    }

    return 0;
}

int getParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int findParent(int parent[], int a, int b) {
    int nodeA = getParent(parent, a);
    int nodeB = getParent(parent, b);
    return (nodeA != nodeB) ? 0 : (nodeB < b) ? -1 : 1;
}