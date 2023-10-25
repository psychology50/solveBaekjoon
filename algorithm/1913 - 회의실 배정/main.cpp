#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
vector<pii> teams;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; ++i) {
        int start, end; cin >> start >> end;
        teams.push_back({end, start});
    }
    sort(teams.begin(), teams.end());

    int res = 0, lastEndTime = 0;
    for (int i=0; i<n; ++i) {
        int start = teams[i].second, end = teams[i].first; 
        
        if (lastEndTime <= start) {
            lastEndTime = end;
            ++res;
        }
    }
    cout << res << "\n";

    return 0;
}