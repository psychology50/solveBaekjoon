#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> p;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    p arr[1000000];
    for (int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        arr[i].first = x; arr[i].second = y;
    }
    sort(arr, arr+n);

    int left = -INF, right = -INF, answer=0;

    for (int i=0; i<n; i++) {
        if (arr[i].first < right) {
            right = max(right, arr[i].second);
        } else {
            answer += right - left;
            left = arr[i].first;
            right = arr[i].second;
        }
    }
    answer += right - left;

    cout << answer << endl;

    return 0;
}