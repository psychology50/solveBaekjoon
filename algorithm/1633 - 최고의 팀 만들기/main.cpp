#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;
using pii = pair<int, int>;

int n;
vector<pii> status;
int cache[MAX][16][16];

int dfs(int now, int white, int black) {
    if (white == 15 && black == 15) return 0;
    if (now == n) return 0;
    
    int& ret = cache[now][white][black];
    if (ret) return ret;

    int tmp = 0;
    if (white < 15) {
        tmp = dfs(now+1, white+1, black) + status[now].first;
    }
    if (black < 15) {
        tmp = max(tmp, dfs(now+1, white, black+1) + status[now].second);
    }

    return ret = max(tmp, dfs(now+1, white, black));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int white, black;
    while (cin >> white >> black) {status.push_back({white, black});}
    n = status.size();
    
    cout << dfs(0, 0, 0);
    return 0;
}