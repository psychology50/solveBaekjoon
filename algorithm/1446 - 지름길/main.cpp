#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

#define MAX 987654321

using namespace std;
typedef tuple<int, int, int> tiii;

int n, d;
vector<tiii> shortcut;
int cache[10001];

int dfs(int now) {
    if (now == 0) return 0; 

    int& ret = cache[now];
    if (ret != MAX) return ret;

    for (tiii& nxt : shortcut) {
        if (get<1>(nxt) > now) continue;

        if (get<1>(nxt) == now) // 현재 지름길 있으면 타고 이동
            ret = min(ret, dfs(get<0>(nxt)) + get<2>(nxt));
        else if (get<1>(nxt) < now) // 다음 지름길 입구까지 이동
            ret = min(ret, dfs(get<1>(nxt)) + (now - get<1>(nxt)));
    }    
    ret = min(ret, now); // 바로 목적지로 이동

    return ret;
}

bool cmp(tiii& a, tiii& b) {
    return (get<0>(a) > get<0>(b));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> d;

    for (int i=0; i<=d; ++i) cache[i] = MAX;
    for (int i = 0; i < n; ++i) {
        int start, end, distance;
        cin >> start >> end >> distance;

        if (end > d) continue;

        for (int pre=0; pre<shortcut.size(); ++pre) {
            if (get<0>(shortcut[pre]) == start && get<1>(shortcut[pre]) == end && get<2>(shortcut[pre]) > distance) {
                shortcut.erase(shortcut.begin() + pre);
            } else {
                continue;
            }
        }
        
        shortcut.push_back({start, end, distance});
    }
    sort(shortcut.begin(), shortcut.end(), cmp);

    cout << dfs(d);

    return 0;
}