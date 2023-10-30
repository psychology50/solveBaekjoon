#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m, l, k;
vector<pii> stars;

int countReflection();

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m >> l >> k;
    for (int i=0; i<k; ++i) {
        int y, x; cin >> y >> x;
        stars.push_back({y, x});
    }

    cout << countReflection() << "\n";
}

int countInRange(int y, int x) {
    int cnt = 0;
    
    for (auto &cur : stars) 
        if ((y <= cur.first && cur.first <= y+l) && (x <= cur.second && cur.second <= x+l))
            ++cnt;

    return cnt;
}

int countReflection() {
    int res = 0;

    for (int i = 0; i < k; ++i) for (int j = 0; j < k; ++j) {
        res = max(res, countInRange(stars[i].first, stars[j].second));
    }

    return k - res;
}