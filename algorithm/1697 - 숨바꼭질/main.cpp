#include <iostream>
#include <queue>
#include <cstring>

#define endl "\n"
#define MAX 100001

using namespace std;

int n, k;
int cache[MAX] = {-1 };
bool visited[MAX] = {false, };

bool isValid(int a) {
    return 0 <= a && a < MAX;
}

void bfs(int source) {
    queue<int> q; q.push(source);
    cache[source] = 0;

    while (!q.empty()) {
        int now = q.front(); q.pop();

        if (now == k) return;

        if (isValid(now + 1) && cache[now + 1] == -1) {
            cache[now + 1] = cache[now] + 1;
            q.push(now + 1);
        }
        if (isValid(now - 1) && cache[now - 1] == -1) {
            cache[now - 1] = cache[now] + 1;
            q.push(now - 1);
        }
        if (isValid(now * 2) && cache[now * 2] == -1) {
            cache[now * 2] = cache[now] + 1;
            q.push(now * 2);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));

    if (n >= k) {
        cout << n - k << endl;
        return 0;
    }

    bfs(n);
    cout << cache[k] << endl;

    return 0;
}