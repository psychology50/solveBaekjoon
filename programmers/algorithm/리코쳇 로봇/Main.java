import java.util.*;

class Solution {
    private static final int[][] dydx = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // 하, 우, 상, 좌
    private static final int EMPTY = 0;
    private static final int D = 1;
    private static final int R = 2;
    private static final int G = 3;
    
    private int n, m;
    private int[][] map;
    private int[][] visited;
    
    public int solution(String[] board) {
        n = board.length;
        m = board[0].length();
        map = new int[n][m];
        visited = new int[n][m];
        Queue<int[]> q = new ArrayDeque<>();

        int targetY = 0, targetX = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            char c = board[i].charAt(j);
            
            if (c == 'G') {
                targetY = i;
                targetX = j;
                map[i][j] = G;
            } else if (c == 'R') {
                q.add(new int[]{i, j});
                visited[i][j] = 1;
                map[i][j] = R;
            } else if (c == 'D') {
                map[i][j] = D;
            } else {
                map[i][j] = EMPTY;
            }
        }
        
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            
            for (int[] d : dydx) {
                int dir = (d[0] != 0) ? 0 : 1; // 0: 상/하, 1: 좌/우
                int[] nxt = getNxt(cur[0], cur[1], dir, d[dir]);
                // System.out.println("현재 좌표: ("+cur[0]+", "+cur[1]+") -> 다음 ("+nxt[0]+", "+nxt[1]+")");
                
                if (visited[nxt[0]][nxt[1]] != 0) continue;
                visited[nxt[0]][nxt[1]] = visited[cur[0]][cur[1]] + 1;
                
                if (nxt[0] == targetY && nxt[1] == targetX) break;
                
                q.add(new int[]{nxt[0], nxt[1]});
            }
        }
        
        return (visited[targetY][targetX] == 0) ? -1 : visited[targetY][targetX] - 1;
    }
    
    private int[] getNxt(int y, int x, int dir, int factor) { // dir 0: 상/하, 1: 좌/우
        int curY = y, curX = x;
        int nxtY = y, nxtX = x;
        
        // System.out.println("("+curY + ", "+curX+")에서 이동 시작");
        while (true) {
            if (dir == 0) {
                nxtY = curY + factor;
            } else {
                nxtX = curX + factor;
            }
            
            if (!(0 <= nxtY && nxtY < n && 0 <= nxtX && nxtX < m)) return new int[]{curY, curX};
            if (map[nxtY][nxtX] == D) return new int[]{curY, curX};
            // System.out.println("-> ("+nxtY+", "+nxtX+")");
            
            curY = nxtY;
            curX = nxtX;
        }
    }
}