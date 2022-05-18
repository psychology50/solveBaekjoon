#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define ll long long
#define endl "\n"

using namespace std;

typedef struct s_coordinate {
    ll x, y;
}              t_coor;
vector<t_coor> graph;
int n;

ll ccw(t_coor a, t_coor b, t_coor c) { // 외적의 정의 이용 (사선 공식)
    return (a.x*b.y + b.x*c.y + c.x*a.y) - (a.x*c.y + b.x*a.y + c.x*b.y);
}

bool angle(t_coor a, t_coor b) {
    ll value = ccw(graph[0], a, b);
    
    if (value) {
        return value > 0;
    } else if (a.y != b.y) {
        return a.y < b.y;
    } else {
        return a.x < b.x;
    }
}

void coorSort() {
    for (int i=1; i < n; i++) {
        if (graph[0].y > graph[i].y || (graph[0].y == graph[i].y && graph[0].x > graph[i].x)) {
            ll tmp = graph[0].y;
            graph[0].y = graph[i].y;
            graph[i].y = tmp;

            tmp = graph[0].x;
            graph[0].x = graph[i].x;
            graph[i].x = tmp;
        }
    }
    sort(graph.begin() + 1, graph.end(), angle);
}

int draw_polygon() {
    stack<t_coor> vertex;

    vertex.push(graph[0]); vertex.push(graph[1]);

    for (int i=2; i<n; i++) {
        while (vertex.size() >= 2) {
            t_coor mid = vertex.top(); // 중간 좌표
            vertex.pop();
            t_coor start = vertex.top(); // 현재 좌표

            if (ccw(start, mid, graph[i]) > 0) { // 각이 유효하지 않으면 최신화하지 않음
                vertex.push(mid);
                break;
            }
        }
        vertex.push(graph[i]);
    }

    return vertex.size();
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    graph.resize(n);
    for (int i=0; i < n; i++)
        cin >> graph[i].x >> graph[i].y;

    coorSort();
    cout << draw_polygon();

    return 0;
}