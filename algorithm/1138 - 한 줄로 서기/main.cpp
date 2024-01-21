#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
int n;
vector<pii> isHeights;
vector<int> res;

bool cmp(pii a, pii b) {
    return (a.second < b.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int tmp; cin >> tmp;

        isHeights.push_back({i, tmp});
    }

    sort(isHeights.begin(), isHeights.end(), cmp);

    for (int now=1; now<n; ++now) {
        int cnt = (isHeights[now] < isHeights[0]) ? 1 : 0;
        for (int pre=1; pre<now; ++pre) {
            if (isHeights[now].first < isHeights[pre].first) ++cnt;
            
            if (isHeights[now].second < cnt) {
                pii tmp = isHeights[now];
                isHeights.erase(isHeights.begin() + now);
                isHeights.insert(isHeights.begin() + pre, tmp);
                break;
            }

        }
    }

    for (pii& tmp : isHeights) {
        cout << tmp.first << " ";
    }

    return 0;
}