#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1e9

using namespace std;
typedef pair<int, int> p;

int n, d;
vector<p> dist, tmp;

void input_value() {
    cin >> n;

    for (int i=0; i<n; i++) {
        int h, o; cin >> h >> o;
        if (h > o) { swap(h, o); } // 무조건 작은 값을 first
        dist.push_back({h, o});
    }
    cin >> d;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input_value();

    for (auto i : dist) { 
        if (i.second - i.first > d) continue; // 애초에 길이 오버인 애들 정리
        tmp.push_back({i.first, 1});
        tmp.push_back({i.second-d, -1}); // d를 평행이동 하다가 범위를 벗어나면 cnt에서 제외
    }
    sort(tmp.begin(), tmp.end());

    int cnt = 0, ans = 0;
    for (auto i : tmp) {
        cnt -= i.second; // second - first <= d라면 second - d <= first가 성립한다.. 즉, cnt기준을 first가 아니라 second로 잡는다.
        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}