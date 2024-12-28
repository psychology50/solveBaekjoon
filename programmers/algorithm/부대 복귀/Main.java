import java.util.*;

class Solution {
    private int[] cost;
    private List<Integer>[] G;
    
    // 정점 개수: 3 <= n <= 100,000 (간선 비용은 모두 1, 0번 정점 없음.)
    // 왕복 간선 roads: 2 <= 길이 <= 500,000 (중복 없이 [u, v] 형태로 반환)
    // 부대 위치 sources: 1 <= 길이 <= 500
    // 목적지 destination
    // 반환: sources 순서대로 강철 부대의 최단 복귀 시간 정보 (복귀 못하는 경우 -1)
    
    // dp 안 쓰면 망함. 다익스트라 쓰면 되지 않을까
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        initGraph(n, roads);
        
        bfs(destination);
        
        int[] answer = new int[sources.length];
        for(int i = 0; i < sources.length; ++i)
            answer[i] = cost[sources[i]];      
        
        return answer;
    }
    
    private void initGraph(int n, int[][] roads) {
        G = new List[n + 1];
        
        for(int i = 0 ; i <= n; ++i)
            G[i] = new ArrayList();
        
        for(int[] road : roads){
            G[road[0]].add(road[1]);
            G[road[1]].add(road[0]);
        }
        
        cost = new int[n + 1];
        Arrays.fill(cost, -1);
    }
    
    private void bfs(int start) {
        Queue<Integer> q = new ArrayDeque();
        q.add(start);
        cost[start] = 0;
        
        while(!q.isEmpty()){
            int cur = q.poll();
            int len = G[cur].size();
            
            for(int i = 0; i < len; ++i){
                int next = G[cur].get(i);
                if(cost[next] == -1){
                    cost[next] = cost[cur] + 1;
                    q.add(next);
                }
            }
        }
    }
}