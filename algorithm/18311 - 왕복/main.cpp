#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


int n;
ll k;
vector<int> goal;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    
    goal.resize(n+1);
    for (int i=0; i<n; ++i) {
        cin >> goal[i];
    }

    for (int i = 0; i<n; ++i) {
        k -= goal[i];
        if (k < 0) {
            cout << i+1;
            return 0;
        }
    }

    for (int i=n-1; i>=0; --i) {
        k -= goal[i];
        if (k < 0) {
            cout << i+1;
            break;
        }
    }

    return 0;
}
