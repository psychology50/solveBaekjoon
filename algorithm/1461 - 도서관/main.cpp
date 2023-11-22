#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
vector<int> books;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    int pos_m = 0;
    for (int i=0, v; i<n; ++i) {
        cin >> v;
        books.push_back(v);
        if (v < 0) ++pos_m;
    }
    sort(books.begin(), books.end());
    int res = 0;
    for (int i = 0; i < pos_m; i+=m) {
        res += abs(books[i] * 2);
    }
    for (int i = n-1; i >= pos_m; i-=m) {
        res += books[i] * 2;
    }   
    
    cout << res - max(abs(books[0]), books[n-1]) << "\n";
    return 0;
}