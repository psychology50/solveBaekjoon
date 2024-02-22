#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;
using ll = long long;

int m;
string target;
vector<string> alphabet[30];
map<string, int> removers;
int cache[1010];

int dfs(int cur) {
    if (cur == target.length()) return 0;
    if (cur > target.length()) return -1;

    int& ret = cache[cur];
    if (ret != -1) return ret;
    ret = 0;

    for (string& str : alphabet[target[cur] - 'a'])
        if (str == target.substr(cur, str.length()))
            ret = max(ret, dfs(cur + str.length()) + removers[str]);
    
    return ret = max(ret, dfs(cur + 1) + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> target >> m;

    string str; int nbr;
    for (int i=0; i<m; ++i) {
        cin >> str >> nbr;
        removers[str] = nbr;
        alphabet[str[0] - 'a'].push_back(str);
    }
    memset(cache, -1 ,sizeof(cache));
    cout << dfs(0);
    return 0;
}