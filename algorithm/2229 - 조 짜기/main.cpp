#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 1001

using namespace std;

int n;
int students[MAX];
int cache[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    
    int age;
    for (int i = 0; i < n; ++i) {cin >> students[i];}

    int mx, mn;
    for (int i=1; i<n; ++i) {
        mx = mn = students[i];
        for (int j=i; j>=0; --j) {
            mx = max(mx, students[j]);
            mn = min(mn, students[j]);
            cache[i] = max(cache[i], cache[j-1]+mx-mn);
        }
    }

    cout << cache[n-1];
    return 0;
}