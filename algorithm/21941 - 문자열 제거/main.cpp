#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using pis = pair<int, string>;

int m;
string target;
vector<pis> removers;
map<string, int> cache;

int dfs(string str) {
    int& ret = cache[str];
    if (ret != 0) return ret;
    ret = str.length();

    for (pis& remover: removers) {
        size_t nPos = str.find(remover.second);
        if (nPos != string::npos) {
            string tmp = str; tmp.erase(tmp.begin() + nPos, tmp.begin() + nPos + remover.second.length());
            return ret = max(ret, dfs(tmp) + remover.first);
        } else {
            // for (int idx=0; idx<str.length(); ++idx) {
            //     string tmp = str; tmp.erase(tmp.begin() + idx);
            //     return ret = max(ret, dfs(tmp) + 1);
            // }
        }
    }

    return ret;
}

bool cmp(pis& a, pis& b) {
    if (a.first == b.first) return a.second.length() < b.second.length();
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> target >> m;
    removers.resize(m);
    for (int i=0; i<m; ++i) cin >> removers[i].second >> removers[i].first;
    sort(removers.begin(), removers.end(), cmp);

    dfs(target);

    int ans = 0;
    for (auto& c : cache) {
        cout << c.first << " -> " << c.second << endl;
        ans = max(ans, c.second);
    }

    cout << ans;
    return 0;
}