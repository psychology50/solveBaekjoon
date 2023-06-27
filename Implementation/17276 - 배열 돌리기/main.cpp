#include <iostream>
#include <cstring>

#define endl '\n'
#define MAX 501

using namespace std;

int arr[MAX][MAX];
int ans[MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    int n, d; 
    int i, j;
    int cnt;

    while (t--) {
        cin >> n >> d;
        for (i=0; i<n; i++) for (j=0; j<n; j++) cin >> arr[i][j]; 

        memcpy(ans, arr, sizeof(arr));

        cnt = (d >= 0) ? d / 45 : (d / 45) + 8;
        while(cnt--) {
            for (i=0; i<n; i++) ans[i][(n+1)/2 - 1] = arr[i][i];
            for (i=0; i<n; i++) ans[i][i] = arr[(n+1)/2 - 1][i];
            for (i=n-1; i>=0; i--) ans[(n+1)/2 - 1][n-1-i] = arr[i][n-1-i];
            for (i=n-1; i>=0; i--) ans[i][n-1-i] = arr[i][(n+1)/2 - 1];
            memcpy(arr, ans, sizeof(ans));
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) cout << ans[i][j] << " ";
            cout << endl;
        } 
    }

    return 0;
}