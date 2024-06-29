import java.util.*;

class Solution {
    private int N, M;
    private final int[][] dydx = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    public int solution(int[][] maps) {
        N = maps.length;
        M = maps[0].length;
        
        int answer = bfs(maps);
        return answer;
    }
    
    private int bfs(int[][] maps) {
        Queue<Point> q = new LinkedList<>();
        int[][] visited = new int[N][M];
        for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) visited[i][j] = -1;
        visited[0][0] = 1;
        
        q.offer(new Point(0, 0));
               
        while (!q.isEmpty()) {
            Point cur = q.poll();
            
            for (int i=0; i<4; ++i) {
                int ny = cur.y() + dydx[i][0];
                int nx = cur.x() + dydx[i][1];
                
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (maps[ny][nx] == 0 || visited[ny][nx] != -1) continue;
                
                visited[ny][nx] = visited[cur.y()][cur.x()] + 1;
                q.offer(new Point(ny, nx));
            }
        }
        
        return visited[N-1][M-1];
    }
    
    private static class Point {
        private int y, x;
        
        Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
        
        int y() {return y;}
        int x() {return x;}
    }
}