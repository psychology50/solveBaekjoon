import java.util.*;

class Solution {
    private static final int INF = Integer.MAX_VALUE;
    private int n;
    private int[][] graph;
    private boolean[][] visited;
    
    // 정점(함정인 정점에 도착하면, 연결된 간선을 모두 역전), 단방향 간선
    // 2 <= n <= 1,000
    // 1 <= e <= 3,000 ([P, Q, S] : P->Q 비용 S, 1 <= S <= 3,000) 
    // 미로를 탈출하는 최단 시간 (언제나 탈출 가능한 경우만 존재)
    
    // trap의 경우 왕복해야 길이 열리는 경우가 존재할 수도 있음. (예, e <- t1 <- t2에서 t1으로 접근하는 경우)
    // 즉, trap이면 방문 처리를 2가지 케이스를 모두 고려해야 함.
    // bfs 쓰면, 상태가 바뀔 우려가 존재..dfs 쓰는 게 안전할 듯
    public int solution(int n, int start, int end, int[][] roads, int[] traps) {
        init(n, roads, traps);
        
        return bfs(start, end, traps);
    }
    
    private void init(int n, int[][] roads, int[] traps) {
        this.n = n;
        
        graph = new int[n+1][n+1];
        for (int i=0; i<=n; ++i) for (int j=0; j<=n; ++j) graph[i][j] = INF;
        
        for (int i=1; i<=n; ++i) graph[i][i] = 0;
        for (int[] road : roads) graph[road[0]][road[1]] = Math.min(graph[road[0]][road[1]], road[2]);
        
        visited = new boolean[n + 1][1 << traps.length]; // 현재 위치에서 각 트랩의 활성 상태 체크
    }
    
    // 시간 초과 개선
    // 1. 역전할 때 실제로 graph를 뒤집어 줄 필요 있는가? -> 방문 처리로 가능은 한데, 문제는 트랩 두 개 붙어있는 경우. 분기 조건이 까다로워짐
    // 2. traps를 매번 탐색하기 보다 배열을 만들지? -> N 크기 배열 만들면 되긴 한데, 해봐야 10개라 큰 이득이 없음
    // 3. dp로 최적화가 가능하지 않은가? 그리디하게 접근할 수는 없는지? -> 다익스트라를 사용한다고 했을 때, 상태를 독립적으로 분리해야 함.
    // 4. 그래프를 인접 리스트 -> 연결 리스트 (역전이 어려워짐)
    private int bfs(int start, int end, int[] traps) {
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]); // [idx, cost, state] 
        pq.add(new int[]{start, 0, 0});
        
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int idx = cur[0], cost = cur[1], state = cur[2];
            
            if (idx == end) return cost; // 기저 사례
            if (visited[idx][state]) continue;
            visited[idx][state] = true;
            
            TrapState trapsState = searchTrapsState(idx, state, traps);
            
            for (int nxt=1; nxt<=n; ++nxt) {
                if (idx == nxt) continue; // 자기 자신 제외
                
                if (trapsState.isTrapCurAndNxt(nxt)) { // 현재-다음 모두 트랩 or 둘 다 아님
                    if (graph[idx][nxt] != INF)
                        pq.add(new int[]{nxt, cost + graph[idx][nxt], trapsState.state});
                } else { // 둘 중 하나가 트랩 (역방향 비용을 저장)
                    if (graph[nxt][idx] != INF) 
                        pq.add(new int[]{nxt, cost + graph[nxt][idx], trapsState.state});
                }
            }
        }
        
        return INF;
    }
    
    private TrapState searchTrapsState(int cur, int state, int[] traps) {
        Set<Integer> trapsState = new HashSet<>();
        int s = state;
        boolean isCurrentTrap = false;
        
        for (int i = 0; i < traps.length; i++) {
            int bit = 1 << i;
            
            if ((s & bit) != 0) { // i번 째 trap이 활성 상태라면?
                if (cur == traps[i]) {
                    state &= ~bit; // 현재 트랩 비활성화
                } else {
                    trapsState.add(traps[i]); // 활성화되어 있는 트랩은 유지
                }
            } else {
                if (cur == traps[i]) { // 현재 트랩 노드고, 비활성 상태라면
                    state |= bit; // 현재 트랩 활성화
                    isCurrentTrap = true;
                }  
            }
        }
        
        return new TrapState(state, trapsState, isCurrentTrap);
    }
    
    private static class TrapState {
        public int state;
        public Set<Integer> traps;
        public boolean isCurrentTrap;
        
        public TrapState(int state, Set<Integer> traps, boolean isCurrentTrap) {
            this.state = state;
            this.traps = traps;
            this.isCurrentTrap = isCurrentTrap;
        }
        
        public boolean isTrapCurAndNxt(int nxt) {
            return isCurrentTrap == traps.contains(nxt);
        }
    }
}