#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>


#define MAX 1001
#define endl '\n'

using namespace std;

/*
    idea 1. 내가 탔을 때, 따라 타는 사람이 많은 순으로 태우면? => 이 문제는 한 명만 충족하면 다음 사람을 태우므로 부적함

    위상정렬 개념이 나오긴 해야 할 텐데, 그래프 관계까지 고려하면 SCC가 나올 것 같다.
*/

/*
    idea 2
    관계를 매핑했을 때, 사이클이 존재한다면? SCC가 나올까?

    Assum. 모든 노드는 반드시 하위 노드를 한 개씩 가지고 있다.
    (1) 나와 같이 가고 싶은 사람이 없는 경우 => 상위 노드가 없고, 하위 노드만이 존재
    (2) 나와 같이 가고 싶은 사람이 있는 경우 => 상위 노드가 있고, 하위 노드도 존재
    (3) 내가 같이 가고 싶은 사람이 나인 경우 => 상위 노드는 있을 수도 없을 수도, 하위 노드는 부재

    이렇게 되면 최하위 노드에서는 사이클이 반드시 발생한다.
    또한, 최상위 노드를 데려가려면 하위 노드 전부를 데려가야 한다. 
    특히 사이클로 엮인 애들은 한 세트..지긋지긋하다. 이거 때문에 위상 정렬로는 안 된다. 전부 데려가거나, 아무도 안 데려가거나 둘 중 하나다.

    결론 : SCC로 사이클을 찾고, 상위 노드를 하나씩 선택하면서 최대 몇 명을 데려갈 수 있는지 확인한다.
*/

/*
    문제 1. SCC로 사이클을 찾는다.
        -> 그냥 만들면 되는 거고
    문제 2. K명에 최대한 가까이 태울 수 있는 방법을 찾는 최적화 문제.
        -> 최소 인원은 indegree가 0인 사이클 안의 노드 수
        -> 단, 이거 구하려면 indegree가 0인 사이클이 하나여야 한다.
*/

int n, k;
int visited[MAX], sccLabel[MAX], sccSize[MAX];
int idx=0, sccCnt=0;
int compNum = 0;
int compSize[MAX], minCompSize[MAX], maxCompSize[MAX];
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

void makeDAG() { // Directed Acyclic Graph
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
        compSize[i] = ++compNum; // indegree가 0인 노드는 SCC의 최상위 노드이므로, 최소 인원은 1명이다.
        minCompSize[compNum] = maxCompSize[compNum] = sccSize[i]; // SCC의 크기를 저장한다.
    }

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int nxt : graph[curr]) {
            compSize[nxt] = compSize[curr]; // nextNodeNum의 최소 인원은 currNodeNum의 최소 인원 + 1이다.
            maxCompSize[compSize[nxt]] += sccSize[nxt]; // nextNodeNum의 최대 인원은 currNodeNum의 최대 인원 + nextNodeNum의 크기이다.

            if (--indegree[nxt] == 0) q.push(nxt);
        }
    }
}

// cache[now][k] : now번째 노드에서 value명을 데려갈 때, 최대 데려갈 수 있는 사람 수
//  1. now번째 노드를 데려가지 않는 경우
//      cache[now][k] = knapsack(now+1, value)
//  2. now번째 노드를 데려가는 경우
//      cache[now][k] = knapsack(now+1, value - sccSize[now]) + sccSize[now]
int knapsack(int now, int value) {
    if (now > compNum) return 0; // 더 이상 노드가 없다면 종료한다.

    int& ret = cache[now][value];
    if (ret != -1) return ret;

    ret = knapsack(now+1, value); // now번째 노드를 데려가지 않는 경우
    if (value >= minCompSize[now]) {
        for (int i=minCompSize[now]; i<=maxCompSize[now]; i++) {
            if (i > value) break;
            ret = max(ret, knapsack(now+1, value-i) + i);
        }
    }

    return ret;
}