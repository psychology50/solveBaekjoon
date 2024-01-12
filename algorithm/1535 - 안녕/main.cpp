#include <iostream>
#include <cmath>

using namespace std;
int n, res=0;
int damage[21];
int happiness[21];

void dfs(int now, int health, int happy) {
    if (health <= 0) return;
    if (now > n) return;
    res = max(res, happy);

    dfs(now+1, health-damage[now], happy+happiness[now]);
    dfs(now+1, health, happy);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {cin >> damage[i];}
    for (int i = 0; i < n; ++i) {cin >> happiness[i];}

    dfs(0, 100, 0);
    cout << res;

    return 0;
}