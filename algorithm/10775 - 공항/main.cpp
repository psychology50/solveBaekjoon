#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;
int G, P;
int parent[MAX];
vector<int> p;

int F(int x) { 
    return parent[x] = (parent[x] == x) ? x : F(parent[x]);
}

void U(int a, int b) {
    a = F(a), b = F(b);
    
    if (a <= b) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> G >> P; p.resize(P);
    for (int& v: p) {cin >> v;}
    for (int i=0; i<=G; ++i) parent[i] = i;

    int ret = 0;
    for (int i=0; i<P; ++i) {
        int gate = F(p[i]);
        if (gate != 0) {
            U(gate - 1, gate); ++ret;
        } else {break;}
    }
    cout << ret;
    return 0;
}