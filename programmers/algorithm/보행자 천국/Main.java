class Solution {
    // private static final int[][] dydx = {{0, 1}, {1, 0}}; 
    
    private int[][] cityMap;
    private int[][] map;
    int MOD = 20170805;
    // private int M, N;
    // private int[][] map;
    // private boolean[][] visited;
    
    public int solution(int m, int n, int[][] cityMap) {
        this.cityMap = cityMap;
        map = new int[m + 1][n + 1];

        for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1)
                map[i][j] = 1;
            else {
                if (cityMap[i - 1][j - 1] == 0)
                    map[i][j] = (getTopValue(i, j) + getLeftValue(i, j)) % MOD;
                else
                    map[i][j] = 0;
            }
        }

        return map[m][n];
    }

    public int getTopValue(int rowIndex, int columnIndex) {
        for (int i = rowIndex - 1; i > 0; i--) {
            if (cityMap[i - 1][columnIndex - 1] != 2)
                return map[i][columnIndex];
        }

        return 0;
    }

    public int getLeftValue(int rowIndex, int columnIndex) {
        for (int i = columnIndex - 1; i > 0; i--) {
            if (cityMap[rowIndex - 1][i - 1] != 2)
                return map[rowIndex][i];
        }

        return 0;
    }
    
//     // 1 <= m(row), n(col) <= 500
//     // cityMap[i] : 0(자율 통행), 1(자동차 통행 금지), 2(좌/우회전 금지)
//     // 반환: 이동 가능한 전체 경로수 (최소 경로만 체크하는 거였음..^^)
//     // dfs 타임아웃. dp 쓰는 문젠듯
//     public int solution(int m, int n, int[][] cityMap) {
//         M = m;
//         N = n;
//         map = new int[m][n];
//         for (int i=0; i<m; ++i) map[i] = cityMap[i].clone();

//         visited = new boolean[m][n];
//         visited[0][0] = true;
//         return dfs(0, 0, -1) % MOD;
//     }
    
//     private int dfs(int row, int col, int preDir) {
//         if (row == M-1 && col == N-1) return 1;
        
//         int result = 0;
//         for (int dir=0; dir<2; ++dir) {
//             int ny = row + dydx[dir][0], nx = col + dydx[dir][1];
            
//             if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue; // 범위 이탈
//             if (visited[ny][nx]) continue; // 이미 방문한 경우
//             if (map[ny][nx] == 1) continue; // 막힌 경우
//             if (map[row][col] == 2 && preDir != -1 && preDir != dir) continue; // 현재 직진 경로에서 직진 안 하는 경우 (처음 시작 제외)
            
//             visited[ny][nx] = true;
//             result += dfs(ny, nx, dir);
//             visited[ny][nx] = false;
//         }
        
//         return result % MOD;
//     }
}