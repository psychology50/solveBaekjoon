#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

#define MAX 21
#define endl "\n"

using namespace std;

typedef tuple<int, int, int, int> tiiii;

struct STUDENT {
    int num;
    int favor[4];
};

int res[MAX][MAX];
STUDENT arr[MAX * MAX];

int vc[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

bool cmp(tiiii a, tiiii b) {
    if (get<0>(a) > get<0>(b)) return true;
    if (get<0>(a) == get<0>(b)) {
        if (get<1>(a) > get<1>(b)) return true;
        if (get<1>(a) == get<1>(b)) {
            if (get<2>(a) < get<2>(b)) return true;
            if (get<2>(a) == get<2>(b)) {
                if (get<3>(a) < get<3>(b)) return true;
            }
        }
    }
    return false;
}

void go(int n, int idx) {
    vector<tiiii> check;
    
    for (int y=0; y<n; y++) for (int x=0; x<n; x++) {
        int cnt_e = 0, cnt_f = 0;
        if (res[y][x] != 0) continue;

        for (auto v : vc) {
            int ny = y + v[0];
            int nx = x + v[1];

            if (!(0 <= ny && ny < n && 0 <= nx && nx < n)) continue;
            
            for (auto v : arr[idx].favor) 
                if (res[ny][nx] == v) cnt_f++;
            if (res[ny][nx] == 0) cnt_e++;
        }
        check.push_back({cnt_f, cnt_e, y, x});
    }
    sort(check.begin(), check.end(), cmp);

    tiiii tmp = check.front();
    res[get<2>(tmp)][get<3>(tmp)] = arr[idx].num;
}

int check_favor(int n) {
    int sum = 0;

    for (int y=0; y<n; y++) for (int x=0; x<n; x++) {
        int cnt = 0;

        for (auto v : vc) {
            int ny = y + v[0];
            int nx = x + v[1];

            if (!(0 <= ny && ny < n && 0 <= nx && nx < n)) continue;
            
            for (int i=0; i<n*n; i++) {
                if (res[y][x] == arr[i].num) {
                    for (auto v : arr[i].favor) {
                        if (res[ny][nx] == v) cnt++;
                    }
                    break;
                }
            }
        }
        sum += (cnt == 0) ? 0 : pow(10, cnt-1);
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    
    for(int i=0; i < n*n; i++) {
        cin >> arr[i].num;
        for(int j=0; j < 4; j++) cin >> arr[i].favor[j];
    }

    for(int idx=0; idx<n*n; idx++) go(n, idx);

    cout << check_favor(n) << endl;

    return 0;
}