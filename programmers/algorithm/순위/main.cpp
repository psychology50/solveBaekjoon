#include <string>
#include <vector>
#include <cstring>

#define MAX 101

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
vi win[MAX], defeat[MAX];
bool visited[MAX];

int dfs(int cur, vi arr[MAX]) {
    visited[cur] = true;
    
    int ret = 0;
    
    for (int& nxt : arr[cur]) {
        if (visited[nxt]) continue;
        ret += dfs(nxt, arr) + 1;
    }
    
    return ret;
}

int solution(int n, vvi results) {
    for (vi& result : results) {
        win[result[0]].push_back(result[1]);
        defeat[result[1]].push_back(result[0]);
    }
    
    int ret=0, cnt;
    for (int i=1; i<=n; ++i) {
        memset(visited, false, sizeof(visited));
        cnt = dfs(i, win);
        cnt += dfs(i, defeat);
        
        if (cnt == n-1) {
            ++ret;
        }
    }
    return ret;
}