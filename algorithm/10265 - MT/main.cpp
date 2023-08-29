#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

#define MAX 1001
#define endl '\n'

using namespace std;

int n, k;
int visited[MAX], sccLabel[MAX], sccSize[MAX];
int idx=0, sccCnt=0;
int compNum = 0;
int compIdx[MAX], minCompSize[MAX], maxCompSize[MAX];
vector<int> adj[MAX];
int cache[MAX][MAX];
stack<int> s;

void init();
void tarjan();
int makeSSC(int curr);
void makeDAG();
int knapsack(int now, int value);
bool finished[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    tarjan();
    makeDAG();
    cout << knapsack(1, k) << endl;
}

void init() {
    cin >> n >> k;

    for (int i = 0, u; i < n; i++) {
        cin >> u;
        adj[u-1].push_back(i);
    }

    for (int i=0; i<MAX; i++) memset(cache[i], -1, sizeof(cache[i]));
    memset(sccLabel, -1, sizeof(sccLabel));
    fill(&cache[0][0], &cache[MAX-1][MAX], -1);
}

void tarjan() {
    for (int i = 0; i < n; i++)
        if (!visited[i]) makeSSC(i);
}

int makeSSC(int curr) {
    int dfsn = visited[curr] = ++idx; // DFS 탐색 순서를 저장한다.
    s.push(curr);

    for (int nxt : adj[curr]) {
        if (!visited[nxt]) dfsn = min(dfsn, makeSSC(nxt)); // 방문하지 않은 노드라면 DFS를 계속 진행한다.
        else if (sccLabel[nxt] == -1) dfsn = min(dfsn, visited[nxt]); // 방문은 했지만, 아직 SCC로 묶이지 않은 노드라면 
    }

    if (dfsn == visited[curr]) { // DFS 탐색 순서가 현재 노드의 순서와 같다면 SCC를 생성한다.
        while (true) {  
            int node = s.top(); s.pop();
            sccLabel[node] = sccCnt; // SCC 번호를 저장한다.
            sccSize[sccCnt]++; // SCC의 Component 크기를 저장한다.
            if (node == curr) break; // 현재 노드가 SCC의 루트라면 SCC 생성을 마친다.
        }
        sccCnt++;
    }

    return dfsn;
}

void makeDAG() {
    vector<int> graph[MAX];
    int indegree[MAX] = {0};

    for (int i=0; i<n; i++) {
        int nodeNum = sccLabel[i];
        for (int adjNode : adj[i]) {
            int nextNodeNum = sccLabel[adjNode];
            if (nodeNum == nextNodeNum) continue;
            graph[nodeNum].push_back(nextNodeNum); // nodeNum -> nextNodeNum
            indegree[nextNodeNum]++; // nextNodeNum의 indegree 증가
        }  
    }

    queue<int> q;
    for (int i=0; i<sccCnt; i++) if (indegree[i] == 0) {
        q.push(i);
        compIdx[i] = ++compNum;
        minCompSize[compNum] = maxCompSize[compNum] = sccSize[i]; // SCC의 크기를 저장한다.
    }
    cout << endl;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int nxt : graph[curr]) {
            compIdx[nxt] = compIdx[curr]; // nextNodeNum의 최소 인원은 currNodeNum의 최소 인원 + 1이다.
            maxCompSize[compIdx[nxt]] += sccSize[nxt]; // nextNodeNum의 최대 인원은 currNodeNum의 최대 인원 + nextNodeNum의 크기이다.

            if (--indegree[nxt] == 0) q.push(nxt);
        }
    }
}

int knapsack(int now, int value) {
    if (now > compNum) return 0;

    int& ret = cache[now][value];
    if (ret != -1) return ret;

    ret = knapsack(now+1, value);
    if (value >= minCompSize[now]) {
        for (int i=minCompSize[now]; i<=maxCompSize[now]; i++) {
            if (i > value) break;
            ret = max(ret, knapsack(now+1, value-i) + i);
        }
    }

    return ret;
}