#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;
using psi = pair<string, int>;
using pss = pair<string, string>;

int n;
vector<pss> manitto;
map<string, int> idx;
int node[21];

int F(int now) {
    if (now == node[now]) return now;
    return F(node[now]);
}

void U(int& a, int& b) {
    int x = F(a), y = F(b);

    if (x < y) node[y] = x;
    else node[x] = y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t = 0;
    while (true) {
        idx.clear(); manitto.clear();

        cin >> n; if (n == 0) break;

        string from, to; int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> from >> to; 
            manitto.push_back({from, to});

            if (idx[from] == 0) idx[from] = ++cnt;
            if (idx[to] == 0) idx[to] = ++cnt;
            node[i] = i;
        }

        for (auto& m : manitto) {
            U(idx[m.first], idx[m.second]);
        }

        set<int> res;
        for (int i = 1; i <= n; ++i) {
            res.insert(F(node[i]));
        }

        cout << ++t << " " << res.size() << "\n";
    }

    return 0;
}