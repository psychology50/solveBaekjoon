#include <bits/stdc++.h>

using namespace std;
int n, m;

map<string, string> sites;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;

    string site, pw;
    for (int i = 0; i < n; ++i) {
        cin >> site >> pw;
        sites[site] = pw;
    }

    for (int j = 0; j < m; ++j) {
        cin >> site;
        cout << sites[site] << "\n";
    }

    return 0;
}