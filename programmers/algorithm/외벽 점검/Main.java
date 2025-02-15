import java.util.*;

class Solution {
    private int len, answer;
    private int[] weakCase;
    private boolean[] visited;
    
    // 레스토랑: 원, 총 둘레 n미터 (몇몇 지점이 취악함)
    // 원 둘레: 1 <= n <= 200
    // 취약 지점 위치(오름차순): 1 <= weak.length <= 15
    // 각 친구가 1시간 동안 이동할 수 있는 거리: 1 <= dist.length <= 8
    // 반환: 취약 지점 점검을 위한 친구 수 최소값 (친구 모두 투입해도 취약 지점 전부 점검 불가능하면 -1)
    public int solution(int n, int[] weak, int[] dist) {
        len = weak.length;
        weakCase = new int[len*2];
        
        // 원을 일자로 만들어서 취약 지점을 2배로 늘림 (ex: n == 10 & [1, 5, 6, 10] -> [1, 5, 6, 10, 11, 15, 16, 20])
        for (int i=0; i<2; ++i) for (int j=0; j<len; ++j) {
            weakCase[j+(i*len)] = weak[j] + (i*n);
        }
        
        Arrays.sort(dist);
        answer = -1;
        visited = new boolean[dist.length];
        
        // 가장 탐색 범위가 넓은 친구를 1명씩 추가하면서 탐색
        for (int i=1; i<=dist.length; ++i) {
            int[] friends = new int[i];
            System.arraycopy(dist, dist.length - i, friends, 0, i);
            
            dfs(0, new int[i], friends);
            
            if (answer > 0) break;
        }
        
        return answer;
    }
    
    // 친구들의 순열을 구하면서 취약 지점을 점검할 수 있는지 확인
    // ex: 친구들이 [4, 2, 1]만큼 이동할 수 있다면, [4, 2, 1], [4, 1, 2], [2, 4, 1] 등의 조합을 만들어 시도.

    // 왜 친구 배치 조합을 만드는가??
    // ex: 취약지점 [1, 5, 10, 13, 17, 20]이고, 세 친구가 각각 [4, 2, 1] 거리를 이동 가능할 때,
    // 1. [4, 2, 1]로 배치하는 경우
    //    - 1번 친구(4): 1 → 5 점검 가능
    //    - 2번 친구(2): 10 → 10,13 중 하나만 점검 가능
    //    - 3번 친구(1): 나머지 점검 불가능
    // 2. [2, 4, 1]로 배치하는 경우
    //    - 1번 친구(2): 1 → 1,5 점검 가능
    //    - 2번 친구(4): 10 → 10,13,17 점검 가능
    //    - 3번 친구(1): 20 점검 가능
    private void dfs(int n, int[] dist, int[] friends) {
        if (n == friends.length) {
            if (canAllCheck(dist)) {
                answer = n;
            }
            return;
        }
        
        for (int i=0; i<friends.length; ++i) if (!visited[i]) {
            visited[i] = true;
            dist[n] = friends[i];
            dfs(n+1, dist, friends);
            visited[i] = false;
        }
    }
    
    // 주어진 순서로 친구들을 배치했을 때, 취약 지점을 전부 점검할 수 있는지 확인
    private boolean canAllCheck(int[] dist) {
        for (int i=0; i<len; ++i) {
            int idx = i;
            
            for (int d : dist) {
                int pos = weakCase[idx++] + d;
                while (idx < weakCase.length && weakCase[idx] <= pos) ++idx;
            }
            
            if (idx - i >= len) return true;
        }
        
        return false;
    }
}