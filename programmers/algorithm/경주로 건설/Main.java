import java.util.*;

class Solution {
    private static int[][] dydx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상, 하, 좌, 우
    private int result = Integer.MAX_VALUE;
    private int[][] visited;
    private int N;
    
    // N * N (3 <= N <= 25)
    // 0: 빈 공간, 1: 벽
    // 출발점 (0, 0), 도착점 (N-1, N-1)
    // 상, 하, 좌, 우 도로 연결 가능 (벽 있으면 안 됨)
    // 직선도로 100원, 코너 500원
    // 반환: 최소 비용 건설
    
    // 그리디하게 접근 -> 방문 정점, 벽 제외하고, 직선 경로 우선 탐색 (안 되면 코너링)
    // N이 작아서, 전부 탐색해도 될 듯함. => 안됨 ㅋㅋ
    public int solution(int[][] board) {
        N = board.length;
        visited = new int[N][N];
        for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) visited[i][j] = Integer.MAX_VALUE;
        
        return bfs(board);
    }

    private int bfs(int[][] board) {
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]); // [y, x, cost, dir]
        
        visited[0][0] = -1;
        for (int i=1; i<4; i += 2) {
            int ny = dydx[i][0], nx = dydx[i][1];
            if (board[ny][nx] == 1) continue;
            visited[ny][nx] = -1;
            pq.add(new int[]{ny, nx, 100, i});
        }
        
        int lastCost = Integer.MAX_VALUE;
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            
            int y = cur[0], x = cur[1];
            int cost = cur[2], dir = cur[3];
            
            // System.out.println("현재 위치: (" + y + ", " + x + ") -> 비용: " + cost);
            
            if (y == N-1 && x == N-1) {
                if (lastCost == cost) {
                    break;
                }
                
                lastCost = Math.min(lastCost, cost);
            }            
            
            for (int d=0; d<4; ++d) {
                int ny = y + dydx[d][0], nx = x + dydx[d][1];
                
                if (0 > ny || ny >= N || 0 > nx || nx >= N) continue;
                if (board[ny][nx] == 1) continue;
                
                int nxtCost = 0;
                nxtCost = ((dir < 2 && d < 2) || (dir >= 2 && d >= 2)) ? cost + 100 : cost + 600;
                
                if (nxtCost <= visited[ny][nx]) {
                    pq.add(new int[]{ny, nx, nxtCost, d});
                    visited[ny][nx] = nxtCost;
                }
            }
        }
        
        return lastCost;
    }
}