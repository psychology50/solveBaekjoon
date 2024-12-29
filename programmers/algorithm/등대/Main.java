import java.util.*;

class Solution {
    private List<Integer>[] graph;
    // private boolean[] isTurnOn;
    // private boolean[] visited;
    private int answer;
    
    // 등대: 2 <= n <= 100,000 (1~n)
    // 뱃길: n-1개 (모든 등대는 이어져 있음. n-1개 이므로 순환 간선이 생길 수 없음.)
    // 불: 인접한 노드 둘 중 하나는 켜져있어야 함.
    // 결과: 최소로 킨 등대 개수
    
    // 모두 껐다 켜보면서 bfs? 타임 오버 우려
    // 인접한 등대 중 하나라도 불이 켜지지 않는 등대가 존재하면, 그 중 인접 노드가 더 많은 쪽에서 키는 게 best??
    // 1트 실패: 리프 노드는 언제나 false인 것이 최선?
    public int solution(int n, int[][] lighthouse) {
        graph = new List[n+1];
        for (int i=0; i<=n; ++i) graph[i] = new ArrayList<>();
        for (int[] edge: lighthouse) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }
        // isTurnOn = new boolean[n+1];
        // visited = new boolean[n+1];
        
        dfs(1, 0);
        
        // bfs();
        
        // int answer = 0;
        // for (int i=1; i<=n; ++i) if (isTurnOn[i]) {
        //     // System.out.print(i + " ");
        //     ++answer;
        // }
        return answer;
    }
    
    public int dfs(int cur, int pre) {
        if (graph[cur].size() == 1 && graph[cur].get(0) == pre) // 리프 노드면 패스
            return 1; // 상대 노드에서 켜야한다고 반환

        int requireCnt = 0;
        for (Integer nxt: graph[cur]) {
            if (nxt.intValue() == pre) continue; // 지나온 경로면 패스
            requireCnt += dfs(nxt.intValue(), cur);
        }

		//해당 노드가 불을 킬 필요 없으니, 상대 노드에서 켜야 함.
		if (requireCnt == 0) 
        	return 1;
        
        //해당 노드가 불을 켜야함
        ++answer;
        return 0;
    }
    
//     private void bfs() {
//         Queue<Integer> q = new ArrayDeque<>();
//         q.offer(1);
        
//         while (!q.isEmpty()) {
//             int cur = q.poll().intValue();
//             visited[cur] = true;
            
//             for (Integer nxt : graph[cur]) {
//                 if (visited[nxt.intValue()]) continue;
                
//                 if (!isTurnOn[cur] && !isTurnOn[nxt.intValue()]) {
//                     if (graph[cur].size() > graph[nxt.intValue()].size()) {
//                         isTurnOn[cur] = true;
//                     } else {
//                         isTurnOn[nxt.intValue()] = true;
//                     }
//                 }
                
//                 q.offer(nxt);
//             }
//         }
//     }
}