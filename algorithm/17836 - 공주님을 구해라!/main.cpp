#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m, t;

typedef struct Node {
    int y, x;
    bool isGram;
} Node;

typedef struct Queen {
    int y, x;
} Queen;
Queen queen;

typedef struct Gram {
    int y, x;
} Gram;
Gram gram;

vector<pii> dydx = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x <= m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    queen = {n-1, m-1};

    char map[n+1][m+1];
    for (int row=0; row<n; ++row) for (int col=0; col<m; ++col) {
        int tmp; cin >> tmp;
        map[row][col] = tmp;
        if (tmp == 2) gram = {row, col};
    }

    queue<Node> q;
    q.push({1, 1, false});
    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        if (!inRange(cur.y, cur.x)) continue;
    }

    return 0;
}