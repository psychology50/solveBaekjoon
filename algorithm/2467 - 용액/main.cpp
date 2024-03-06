#include <bits/stdc++.h>

#define INF 2e9

using namespace std;
using ll = long long;

int n;
vector<int> solutes;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; solutes.resize(n);
    for (int& solute: solutes) cin >> solute;

    int l, r, start, end;
    l = start = 0, r = end = solutes.size() - 1;
    int ret = INF, sum;
    while (start <= end) {
        sum = solutes[start] + solutes[end];
        if (abs(sum) <= abs(ret)) {
            ret = sum;

            if (start != end) {
                l = start, r = end;
            }
        }

        if (abs(solutes[start]) > abs(solutes[end])) ++start;
        else --end;
    } 

    cout << solutes[l] << " " << solutes[r];
    return 0;
}