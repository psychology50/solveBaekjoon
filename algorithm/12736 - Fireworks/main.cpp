#include <iostream>
#include <algorithm>
#include <queue>

#define ll long long
#define endl "\n"
using namespace std;

priority_queue<ll> *pq[300010];
int p[300010], c[300010], sz[300010];
ll t[300010]; // t에 대한 f_i(t): 서브트리에서 t시간에 터뜨리기 위한 최소 비용

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    for (int i=2; i<=N+M; i++) cin >> p[i] >> c[i]; // P_i: 정점정보, C_i: 가중치
    for (int i=N+1; i<=N+M; i++) pq[i] = new priority_queue<ll>(2, 0); // 폭약
    for (int i=N+M; i; i--) {
        while (sz[i]--) pq[i] -> pop(); // heavy 간선에 속하지 않은 서브트리 잘라냄
        // 기울기가 1씩 증가하는 원소 t를 저장한다.
        ll right = pq[i]->top(); pq[i]->pop();
        ll left = pq[i]->top(); pq[i]->pop();
        pq[i] -> push(right + c[i]);
        pq[i] -> push(left + c[i]);
        t[p[i]] += t[i] + c[i]; // x축 이동 (t[0]이 문제 조건의 가중치 총합이 됨.)
        if (!pq[p[i]]) { // 부모 노드가 비어있다면 그냥 union
            pq[p[i]] = pq[i];
            continue;
        } // 비어있지 않다면 pq 병합 시작
        // HLD 원칙에 따라 서브트리 사이즈가 더 커야 heavy 간선에 속함.
        if (pq[p[i]]->size() < pq[i]->size()) swap(pq[p[i]], pq[i]);
        // 병합
        while(!pq[i] -> empty()) pq[p[i]]->push(pq[i]->top()), pq[i] -> pop();
        sz[p[i]]++; // heavy 간선 외 서브트리 개수 추가 (이후 무거운 간선에서 제거)
    } pq[0] -> pop();
    while (!pq[0]->empty()) t[0] -= pq[0]->top(), pq[0]->pop();
    cout << t[0] << endl;
    return 0;
}