import java.util.*;

class Solution {

    // n(정점 개수), s(출발 정점), a(a 도착 정점), b(b 도착 정점), fares(간선 무게)
    // 3 <= n <= 200
    // s, a, b는 모두 다름
    // fares: 2 <= M <= n*(n-1) / 2 , [c, d, f] : c <-> d (1 <= f원 <= 100,000)
    // 반환: A+B 택시 최소 비용 (합승 안 하는 비용이 더 저렴할 수 있음.)
    
    // dfs + 다익스트라
    //  - dfs: 합승 이동 -> 그냥 반복문 돌려도 될 듯?
    //  - 다익스트라: 개별 이동
    // 그냥 플로이드 워셜로 초기화하면 되는 거 아닌가?
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int[][] dist = new int[n][n];
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) dist[i][j] = (i == j) ? 0 : 30000000;
        
        for (int[] fare: fares) {
            int c = fare[0];
            int d = fare[1];
            int f = fare[2];
            
            dist[c-1][d-1] = Math.min(dist[c-1][d-1], f);
            dist[d-1][c-1] = Math.min(dist[d-1][c-1], f);
        }
        
        for (int k=0; k<n; ++k) for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
        }
        
        int answer = Integer.MAX_VALUE;
        for (int i=1; i<=n; ++i) {
            int cost = dist[s-1][i-1] + dist[i-1][a-1] + dist[i-1][b-1];
            answer = Math.min(answer, cost);
        }
        
        return answer;
    }
}