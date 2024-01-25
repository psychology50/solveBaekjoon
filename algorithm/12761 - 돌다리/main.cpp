#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;
int a, b, n, m;
int stone[MAX];
bool visited[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b >> n >> m;
    int d[] = {1, -1, a, b, -a, -b, a, b};

    queue<int> q;
    visited[n] = true;
    stone[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == m) {
            cout << stone[cur];
            return 0;
        }

        for (int i=0; i<8; ++i) {
            int nxt = (0 <= i && i < 6) ? cur + d[i] : cur * d[i];

            if (nxt < 0 || 100000 < nxt) continue;

            if (!visited[nxt]) {
                visited[nxt] = true;
                stone[nxt] = stone[cur] + 1;
                q.push(nxt);
            }
        }
    }

    return 0;
}