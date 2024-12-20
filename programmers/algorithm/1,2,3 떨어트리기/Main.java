import java.util.*;

class Solution {
    // edge: 부모 -> 자식 (실선: 길, 점선: 길X)
    // 1 <= edge.length <= 100, 1 <= 노드 번호 <= edge 길이 + 1
    // target 길이 = edge 길이 + 1
    // 부모는 자식 중 가장 번호가 작은 노드를 가리키는 간선을 초기 길로 설정
    // (1) 1번 노드(루트)에 숫자 1, 2, 3 하나를 선택해서 떨어트림
    // (2) (1)에서 선택한 수는 길인 간선을 따라 리프 노드까지 떨어짐
    // (3) 숫자가 리프 노드 도착 -> "현재 길로 연결된 자식 노드 다음으로 번호가 큰 자식 노드"를 길로 설정 -> 기존 길 끊음.
    // (4) 원하는 만큼 위 과정 반복 (단, 앞서 떨어트린 숫자가 리프 노드 도착한 후에 새로운 숫자 떨어트려야 함)
    // 목표: 리프 노드에 쌓인 숫자 합을 target과 동일하게 
    // 결과: 사전 순 가장 빠른 경우의 수 (방법 없으면 [-1])
    public int[] solution(int[][] edges, int[] target) {
        int n = edges.length + 1;
        
        // 그래프 초기화
        List<Integer>[] tree = new ArrayList[n];
        for (int i=0; i<n; ++i) tree[i] = new ArrayList<>();
        for (int[] edge : edges) {
            tree[edge[0]-1].add(edge[1]-1);
        }
        for (int i=0; i<n; ++i) Collections.sort(tree[i]);
        
        // 채워야 하는 리프 노드 개수 확인
        int T = 0;
        for (int i=0; i<n; ++i) if (tree[i].isEmpty() && target[i] > 0) ++T;
        
        int[] passCount = new int[n];
        boolean[] clearedLeft = new boolean[n];
        int[] cnt = new int[n];
        List<Integer> clearSeq = new ArrayList<>();
        
        while (T > 0) {
            int cur = 0;
            
            while (tree[cur].size() > 0) { // 리프 노드까지 탐색
                cur = tree[cur].get(passCount[cur]++ % tree[cur].size());
            }
            
            // 모든 수를 1로 채워도 경우의 수가 없는 경우
            if (++cnt[cur] > target[cur]) { 
                return new int[]{-1};
            }
            clearSeq.add(cur); // 방문 리프 노드 순서로 삽입
            
            // 노드의 target 값 ≤ 현재 노드가 보유하고 있는 숫자 개수 * 3 && 미방문 시
            // 만약 조건 충족 안 됐으면, 재방문 필요하므로 unclear
            if (!clearedLeft[cur] && target[cur] <= 3 * cnt[cur]) {
                clearedLeft[cur] = true;
                --T;
            }
        }
        
        List<Integer> tmp = new ArrayList<>();
        for (int i : clearSeq) {
            --cnt[i];
            
            for (int factor=1; factor<=3; ++factor) {
                int value = target[i] - factor;
                
                if (cnt[i] <= value && value <= 3 * cnt[i]) { // 작은 값부터 
                    tmp.add(factor);
                    target[i] -= factor;
                    break;
                }
            }
        }
        
        int[] answer = new int[tmp.size()];
        for (int i=0; i<tmp.size(); ++i) answer[i] = tmp.get(i);
        return answer;
    }
}