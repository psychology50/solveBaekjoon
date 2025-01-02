import java.util.*;

class Solution {
    public int solution(int n, int m, int[][] edge_list, int k, int[] gps_log) {
        int dp[][] = new int[k][n+1]; // [i][j]: i번째 목적지에 j(위치)가 왔을 때 최소 횟수
        List<Integer> li[] = new List[n+1];
        for(int i=1;i<=n;i++){
            li[i] = new ArrayList<>();
            li[i].add(i); // 자기 자신 연결
        }
        for(int i=0;i<m;i++){
            int a = edge_list[i][0];
            int b = edge_list[i][1];
            li[a].add(b);
            li[b].add(a);
        }
        for(int i=0;i<k;i++) for(int j=1;j<=n;j++) dp[i][j]=1001;
        dp[0][gps_log[0]]=0; // 시작지점 초기화
        
        for(int i=0;i<k-1;i++) for(int j=1;j<=n;j++) {
            if(dp[i][j]==1001) continue;
            
            for(int l=0; l<li[j].size(); l++) { // j번 정점의 연결 정보 조회
                int next = li[j].get(l);
                int nv = 0;
                    
                if(gps_log[i+1] != next) nv=1; // 다음 경로와 일치하지 않으면, 조정 횟수 업데이트
                
                // 다음 번에 이동하는 경우와 현재 조정 점수 중 최소치로 업데이트
                dp[i+1][next] = Math.min(dp[i+1][next], dp[i][j] + nv); // 만약 연결되지 않은 곳이라면, Math.min(1001, 1002)라서 유지
            }
        }
        
        int answer = dp[k-1][gps_log[k-1]];
        return answer == 1001 ? -1 : answer;
    }
    
//     private static int K;
//     private static int target;
//     private boolean[][] canMove;
//     private List<Integer>[] edges;
//     private int[] gpsLog;
    
//     // 택시는 간선(양방향)이 있으면 정점 이동해다님 (교통 상황에 따라 한 거점에 머무를 수도, 왔던 길을 돌아갈 수도 있음)
//     // 택시 이동 경로 중 간에 오류가 있을 때, 이를 최소한으로 수정하여 이동 가능한 경로로 만들고자 함.
//     // ex) 1 -> 2 -> 3 -> 3 -x-> 6 -> 7
//     //  1) 1 -> 2 -> 3 -> 4 -> 6 -> 7
//     //  2) 1 -> 2 -> 3 -> 5 -> 6 -> 7 
//     //  3) 1 -> 2 -> 3 -> 3 -> 5 -> 7
//     // 반환: 이동 가능 경로로 만들기 위한, 최소 오류 수정 횟수 (수정 불가능할 경우 -1)
    
//     // 정점 수 n : 2 <= n <= 200 (거점 번호는 1~n까지)
//     // 간선 수 m : 1 <= m <= 10,000
//     // 연결 도로 정보 edge_list : m*2 크기 이차원 배열 [idx][u, v]
//     // 시간대별 거점 정보 총 개수 k: 2 <= k <= 100
//     // 머물렀던 거점 정보 gps_log 
//     public int solution(int n, int m, int[][] edge_list, int k, int[] gps_log) {
//         K = k;
//         target = gps_log[k-1];
        
//         canMove = new boolean[n+1][n+1];
//         edges = new List[n+1];
//         for (int i=0; i<=n; ++i) {
//             canMove[i][i] = true;
//             edges[i] = new ArrayList<>();
//         }
//         for (int[] edge : edge_list) {
//             edges[edge[0]].add(edge[1]);
//             edges[edge[1]].add(edge[0]);
            
//             canMove[edge[0]][edge[1]] = true;
//             canMove[edge[1]][edge[0]] = true;
//         }
        
//         gpsLog = new int[k];
//         gpsLog = gps_log.clone();
        
//         return dfs(0, gps_log[0], 0, 1);
//     }
    
//     // 로직: gps 정보를 따를 수 없는 경로가 나타나는 경우, 경로 재조정.
//     //  - (1) 다른 인접 간선으로 이동
//     //  - (2) 현재 정점으로 이동한 경우를 취소하고, 이전 정점에서 재시도.
//     // 예외 처리
//     //  - 경로 보정 중 왔던 길을 되돌아가는 건 최소 조건에 부합하지 않으므로, 반드시 방문처리로 예외 처리
//     //  - 이동 횟수가 k를 넘어도 제외
//     // 반환: 경로 보정 횟수
//     // 매개변수
//     //  - pre: 이전 위치
//     //  - cur: 현재 위치
//     //  - k: 최대 깊이, depth: 현재 깊이
//     //  - cnt: 보정 횟수
//     private int dfs(int pre, int cur, int cnt, int depth) {
//         if (depth == K-1) {
//             return (cur == target) ? cnt : Integer.MAX_VALUE;
//         }
        
//         int result = Integer.MAX_VALUE;
        
//         if (canMove[cur][gpsLog[depth+1]]) {// 다음 정점으로 이동 가능하다면,
//             result = dfs(cur, gpsLog[depth+1], cnt, depth+1);
//         } else { // 애초에 이동 불가능한 경우? 근처 다른 노드로 시도
//             int moveCnt;
            
//             for (Integer nxt : edges[cur]) {
//                 if (pre == nxt.intValue()) continue; // 되돌아가는 경우 방지
                
//                 result = dfs(result, nxt.intValue(), cnt+1, depth+1);
//             }
//         }
        
//         if (result == Integer.MAX_VALUE) { // 위에서 실패 신호 전달 시, 다른 경로로 시도
//             for (Integer nxt : edges[cur]) {
//                 if (gpsLog[depth+1] == nxt.intValue() || pre == nxt.intValue()) continue;
                
//                 result = dfs(result, nxt.intValue(), cnt+1, depth+1);
//             }
//         }
        
//         return result;
//     }
}