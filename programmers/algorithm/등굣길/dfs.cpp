// 정확성 50%, 효율성 0%
// 재귀로 풀어서 그런듯;;

#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

#define MOD 1000000007
#define MAX 101

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
int targetY, targetX;
int cache[MAX][MAX];

int dfs(int y, int x, vvi& puddles) {
    if (y == targetY && x == targetX) return 1;
    if (!(1 <= y && y <= targetY && 1 <= x && x <= targetX)) return 0;
    for (vi& v : puddles) if (y == v[1] && x == v[0]) return 0;
    
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    ret = 0;
    
    ret += dfs(y+1, x, puddles);
    ret += dfs(y, x+1, puddles);
    
    return ret;
}

int solution(int m, int n, vvi puddles) {
    targetY = n, targetX = m;
    memset(cache, -1, sizeof(cache));
    dfs(1, 1, puddles);
    
    return (cache[1][1] == -1) ? 0 : cache[1][1] % MOD;
}