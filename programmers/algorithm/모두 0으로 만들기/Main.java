import java.util.*;

class Solution {
    // 최소한의 행동으로 모든 점들의 가중치를 0으로 만들기 (불가능하면 -1)
    // 임의 연결된 두 점에서 한 쪽은 1 증가, 한 쪽은 1 감소
    // 정점 가중치 a: 2 <= V <= 300,000 (-1,000,000 <= a[i] <= 1,000,000)
    // 간선 edges는 V-1개 [u, v]

    // dfs 돌리는 순간 타임 오버, bottom up으로 0으로 만들면?
    //  - 트리 형태..순환 간선이 없음을 가정. but, 부모가 여러 개면? 순환 간선이 없는 무방향 그래프이므로 무시합시다.
    // root와 leaf를 어떻게 판단할 것인가? (연결 정점이 한 개인 경우 leaf, root는 몰루)
    // 무식하게 bottom up하면, 아직 모두 갱신 안 됐는데 부모 호출할 수도 있음. (dfs로 관계 정리할 수 있긴 한데, 그럼 타임 아웃)
    // 자기 차례가 와도 연결 정점의 방문 처리가 (연결 정점 개수 - 1)이 되지 않으면, 다시 Queue 삽입?
    
    // 시간 초과...깊이를 indgree로 판단해보자.
    public long solution(int[] a, int[][] edges) {
        List<Integer>[] graph = new List[a.length];
        int[] indegree = new int[a.length];
        int[] points = new int[a.length];
        int answer = 0;
        
        for (int i=0; i<a.length; ++i) {
            graph[i] = new ArrayList<>();
            points[i] = a[i];
            answer += a[i];
        }
        
        if (answer != 0) return -1;
        
        for (int[] edge: edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
            
            ++indegree[edge[0]];
            ++indegree[edge[1]];
        }
        
        Queue<Integer> q = new ArrayDeque<>();
        for (int i=1; i<a.length; ++i) if (graph[i].size() == 1) q.add(i);
        
        while (!q.isEmpty()) {
            int cur = q.poll().intValue();
            
            --indegree[cur];
            answer += Math.abs(points[cur]);
            
            for (Integer nxt : graph[cur]) {
                if (indegree[nxt.intValue()] == 0) continue;
                
                --indegree[nxt.intValue()];
                points[nxt.intValue()] += points[cur];
                
                if (indegree[nxt.intValue()] == 1) {
                    if (nxt.intValue() == 0) continue; // 루트를 0이라고 가정
                    q.add(nxt);
                }
            }
        }
         
        return answer;
    }
}