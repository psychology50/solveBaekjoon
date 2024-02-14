#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vvi = vector<vector<int>>;

int n;
vvi graph;

bool cmp(int& a, int& b) {
    return a > b;
}

int dfs(int cur) {
    // 가장 하위 직원이면 0분 반환
    if (graph[cur].empty()) return 0;

    vector<int> v;
    int cnt = 0, ret = 0;

    // 각 부하 직원이 하위 전체에 연락을 돌리는 게 얼마나 걸리는 지 계산
    for (auto nxt: graph[cur]) v.push_back(dfs(nxt));
    sort(v.begin(), v.end(), cmp);

    // 각 직원에게 차례로 연락을 돌려봄.
    // 부하 직원들에게 전파가 가장 오래 걸리는 직속 부하가 언제나 전체 시간을 지배하는가? 모름
    for (int i=0; i<v.size(); ++i) ret = max(ret, v[i] + ++cnt);
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    graph.resize(n);
    for (int child=0; child<n; ++child) {
        int parent; cin >> parent;
        if (parent == -1) continue;
        graph[parent].push_back(child);
    }
    cout << dfs(0);

    return 0;
}