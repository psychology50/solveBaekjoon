#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int N; cin >> N;
    ll ret = 2001e9;
    ll arr[2010];
    for (int i=0; i<N; i++) cin >> arr[i];

    for (int i=0; i<2; i++) {
        priority_queue<int> q;
        ll tmp = 0;
        for (int j=0; j<N; j++) {
            if (!q.empty() && q.top() > arr[j]) {
                tmp += q.top() - arr[j];
                q.pop();
                q.push(arr[j]);
            }
            q.push(arr[j]);
        }
        ret = min(ret, tmp);
        reverse(arr, arr+N);
    }
    cout << ret << endl;
    return 0;
}