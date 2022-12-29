#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define endl "\n"
#define ll long long

using namespace std;
typedef struct s_coordinate {
    int x, y, idx;
}              t_coor;
vector<t_coor> graph;

ll ccw(t_coor start, t_coor mid, t_coor end) {
    return ((ll)start.x*mid.y + (ll)mid.x*end.y + (ll)end.x*start.y) - ((ll)start.x*end.y + (ll)mid.x*start.y + (ll)end.x*mid.y);
}

ll calc_dist(t_coor a, t_coor b) {
    return (ll)(b.x - a.x)*(ll)(b.x - a.x) + (ll)(b.y - a.y)*(ll)(b.y - a.y); // pow를 쓰면 소숫점이 생김
}

bool calc_angle(t_coor a, t_coor b) {
    ll val = ccw(graph[0], a, b);

    if (val) {
        return val > 0;
    } else if (a.y != b.y) {
        if ((a.x == b.x) || (a.x < 0 && b.x < 0 && a.x > b.x)) {
            return calc_dist(graph[0], a) > calc_dist(graph[0], b);
        } else { // 대각선에 놓인 경우
            return a.y < b.y;
        }
    } else { 
        return a.x < b.x;
    }
}

void coorSort(int n) {
    for (int i=1; i < n; i++) {
        if (graph[0].y > graph[i].y || (graph[0].y == graph[i].y && graph[0].x > graph[i].x)) {
            swap(graph[0].y, graph[i].y);
            swap(graph[0].x, graph[i].x);
            swap(graph[0].idx, graph[i].idx);
        }
    }
    sort(graph.begin() + 1, graph.end(), calc_angle);
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        for (int i=0; i<n; i++) {
            int _x, _y; cin >> _x >> _y;
            graph.push_back({_x, _y, i});
        }

        coorSort(n);
        for (auto a : graph) {
            cout << a.idx << ' ';
        }
        cout << endl;

        graph.erase(graph.begin(), graph.end());
        graph.shrink_to_fit();
    }
    return 0;
}