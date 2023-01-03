#include <iostream>
#include <stack>

#define endl "\n"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll calc_area(int n) {
    int idx = 0, height;
    ll w, h;
    ll max_area = 0;
    pii tmp;
    stack<pii> st; st.push(make_pair(0, -1)); // {y, x}

    while (idx <= n) {
        if (idx == n) height = 0; 
        else cin >> height;
         
        while (st.top().first > height) {
            tmp = st.top(); st.pop();

            h = tmp.first;
            w = idx - st.top().second - 1;

            max_area = max(max_area, (ll)w*h);
            cout << "height = " << height << ", idx = " << idx << endl;
            cout << "tmp_height = " << tmp.first << ", tmp_idx = " << tmp.second << endl;
            cout << "prev_height = " << st.top().first << ", prev_idx = " << st.top().second << endl; 

            cout << "w = " << w << ", h = " << h << endl;
            cout << "max_area = " << max_area << endl;
            
            cout << endl;
        }
        if (st.top().first < height) st.push(make_pair(height, idx));

        idx++;    
    }

    return max_area;
}

int main() {
    ios::sync_with_stdio(false); 
    // cin.tie(0); cout.tie(0);
    int n; 

    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << calc_area(n) << endl;
    }

    return 0;
}