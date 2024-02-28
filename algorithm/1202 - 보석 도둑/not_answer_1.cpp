#include <bits/stdc++.h>

#define MAX 300001

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, k;
vector<pii> arr;
vector<int> backpack;
bool isTaken[MAX];

bool cmp(pii& a, pii& b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k; arr.resize(n); backpack.resize(k);
    for (int i=0; i<n; ++i) cin >> arr[i].first >> arr[i].second;
    for (int i=0; i<k; ++i) cin >> backpack[i]; 
    sort(arr.begin(), arr.end(), cmp);
    sort(backpack.begin(), backpack.end());

    ll ret = 0;
    int preM = -1;
    for (int i=0; i<k; ++i) {
        int w = backpack[i];
        int maxV = -1, takenIdx = 0;
        for (int j=0; j<n; ++j) {

            if (isTaken[j]) continue;
            if (arr[j].first > w) break;
            if (preM == arr[j].first) break;

            if (maxV < arr[j].second) {
                maxV = arr[j].second;
                takenIdx = j;
            }

            preM = arr[j].first;
        }
        isTaken[takenIdx] = true;
        ret += maxV;
        w = -1;
    }

    cout << ret;
    return 0;
}