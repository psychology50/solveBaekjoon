#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
using namespace std;
typedef pair<int, ll> pil; 

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, D; cin >> N >> D;
    deque<pil> dq;
    ll ret = -1e15;

    for (int i=0; i<N; i++) {
        pil cache; cache.first = i; 
        cin >> cache.second;

        while (!dq.empty() && dq.front().first < i - D) 
            dq.pop_front();
        if (!dq.empty())
            cache.second = max(cache.second, dq.front().second + cache.second);
        while (!dq.empty() && dq.back().second <= cache.second)
            dq.pop_back();
        ret = max(ret, cache.second);
        dq.push_back(cache);
    }
    cout << ret << endl;
    return 0;
}