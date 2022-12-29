#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <math.h>

#define ll long long
#define MAX 100010

using namespace std;
typedef struct s_coordinate {
    ll x, y;
}              t_coor;
vector<t_coor> graph;
ll Answer;
ll length;

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

int right_angle(t_coor a, t_coor b, t_coor c) {
    ll ac, ab, bc;
    ll ang, tmp;

    ac = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
    ab = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    bc = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));

    tmp = (pow(ab, 2) + pow(bc, 2) - pow(ac, 2)) / (2 * ab * bc);
    ang = acos(tmp);
    ang *= 180 / 3.14159;

    return ang;
}

void coorSort(int n) {
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

int draw_polygon(int n) {
    stack<t_coor> vertex;
    length = 0;

    vertex.push(graph[0]); vertex.push(graph[1]);

    for (int i=2; i<n; i++) {
        while (vertex.size() >= 2) {
            t_coor mid = vertex.top(); // 중간 좌표
            vertex.pop();
            t_coor start = vertex.top(); // 현재 좌표
            if (right_angle(start, mid, graph[i])==0 && ccw(start, mid, graph[i]) > 0) { // 유효한 경우
                cout << "start.x = " <<start.x<< ", start.y = " <<start.y<< " // mid.x = " <<mid.x<< ", mid.y = " <<mid.y<<" // graph[i].x = " <<graph[i].x<< ", graph[i].y = " <<graph[i].y<< endl;
                cout << right_angle(start, mid, graph[i]) << endl;
                vertex.push(mid);
                break;
            }
        }
        vertex.push(graph[i]);
    }
    while (!vertex.empty()) {
        cout << "x = " << vertex.top().x << ", y = " << vertex.top().y << endl;
        vertex.pop();
    }
    return vertex.size();
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T, test_case;

	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
        int n; cin >> n;
        graph.resize(n);

        for (int i=0; i < n; i++)
            cin >> graph[i].x >> graph[i].y;
        coorSort(n);
        for (auto elem : graph) {cout << "x = " << elem.x << ", y = " << elem.y << endl;}

		cout << "Case #" << test_case+1 << endl;
		cout << draw_polygon(n) << endl;
        cout << "================================" << endl;
	}

	return 0;
}