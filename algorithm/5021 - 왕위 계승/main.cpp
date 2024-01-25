#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;

int n, m;
string king;
map<string, ll> blood;
vector<vector<string>> f(3);

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> king;
    blood[king] = 1LL << 52;;

    string str;
    for (int i=0; i<n; ++i) {
        cin >> str, f[0].push_back(str);
        cin >> str, f[1].push_back(str);
        cin >> str, f[2].push_back(str);
    }

    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
        blood[f[0][j]] = blood[f[1][j]] * 0.5 + blood[f[2][j]] * 0.5;
    }

    ll tmp = 1LL << 52;
    string ans;
    for (int i=0; i<m; ++i) {
        cin >> str;
        if (blood[str] > tmp) tmp = blood[str], ans = str;
    }

    cout << ans;

    return 0;
}