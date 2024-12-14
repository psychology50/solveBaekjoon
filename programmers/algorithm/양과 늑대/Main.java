import java.util.*;

class Solution {
    private boolean[] visited;
    private int answer = 0;
    
    // 0: 양, 1: 늑대 (만약, 양 <= 늑대면, 양 다 죽음. => 죽지 않게 하면서, 최대한 많은 양 데리고 오기.)
    // 2 <= N <= 17
    // info: 그래프 정보 (info[0]은 언제나 양(0))
    // edges[i][j]: 간선 정보 (중복 X, 언제나 이진 트리, 0번 노드는 언제나 루트 노드) 
    // bottom-up으로 각 노드에서 아래로 내려갔을 때 얻을 수 있는 최대 양, 최소 늑대 정보를 저장하면?
    // - node[0]: 얻을 수 있는 양, node[1]: 거쳐가야 하는 양
    // - 만약, 한 쪽은 포기해야 한다면??
    // - 한 쪽을 포기했을 때, 다른 한 곳에서 더 큰 이득을 취할 수 있다면?
    public int solution(int[] info, int[][] edges) {
        visited = new boolean[info.length];
        Arrays.fill(visited, false);
        
        visited[0] = true;
        dfs(1, 0, info, edges);
        
        return answer;
    }

    private void dfs(int sheep, int wolf, int[] info, int[][] edges) {
        if (sheep > wolf) answer = Math.max(answer, sheep);
        else return;
        
        for (int[] edge : edges) {
            int parent = edge[0];
            int child = edge[1];
            
            if (visited[parent] && !visited[child]) {
                visited[child] = true;
                
                if (info[child] == 0) dfs(sheep+1, wolf, info, edges);
                else dfs(sheep, wolf+1, info, edges);
                    
                visited[child] = false;
            }
        }
    }
}