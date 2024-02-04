#include <iostream>
#include <algorithm>

#define MAX 2001

using namespace std;
int n;
int arr[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int& now = arr[i];
        int l=0, r=n-1, tmp;
        while (l<r) {
            tmp = arr[l] + arr[r];
            if (now == tmp) {
                if (l != i && r != i) {++cnt; break;}
                else if (l==i) ++l;
                else if (r==i) --r;
            }
            else if (tmp<now) ++l;
            else if (tmp>now) --r;
        }
    }

    cout << cnt;
    return 0;
}