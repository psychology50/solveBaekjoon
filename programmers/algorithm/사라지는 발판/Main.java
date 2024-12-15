class Solution {
    private final static int[][] dydx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private int[][] visited;
    private int N;
    private int M;
    
    // 1 <= N, M <= 5
    // board[i][j] = 0 || 1
    // aloc, bloc : A, B의 초기 좌표 (같을 수 있음)
    // 결과: 승자(최대한 빠르게 승리하는 경로) 이동 횟수 + 패자(최대한 오래 살아남는 경로) 이동 횟수
    public int solution(int[][] board, int[] aloc, int[] bloc) {
        N = board.length;
        M = board[0].length;
        visited = new int[N][M];
        for (int i=0; i<N; ++i) visited[i] = board[i].clone();
        
        return dfs(aloc, bloc)[1];
    }
    
    private int[] dfs(int[] aloc, int[] bloc) {
        if (isFinished(aloc)) {
            return new int[]{0, 0};
        }
        
        if (aloc[0] == bloc[0] && aloc[1] == bloc[1]) {
            return new int[]{1, 1};
        }
        
        int minMove = Integer.MAX_VALUE;
        int maxMove = 0;
        boolean canWin = false;
        
        for (int[] d: dydx) {
            int ny = aloc[0] + d[0], nx = aloc[1] + d[1];
            
            if (!isValidScope(new int[]{ny, nx}) || visited[ny][nx] == 0) continue;
            
            visited[aloc[0]][aloc[1]] = 0;
            int[] result = dfs(bloc, new int[]{ny, nx}); // 이동할 캐릭터 관점 swap
            visited[bloc[0]][bloc[1]] = 1;
            
            if (result[0] == 0) {
                canWin = true;
                minMove = Math.min(minMove, result[1]);
            }
            
            if (!canWin) {
                maxMove = Math.max(maxMove, result[1]);
            }
        }
        
        return new int[]{(canWin ? 1 : 0), (canWin ? minMove + 1 : maxMove + 1)};
    }
    
    private boolean isFinished(int[] cur) {
        for (int[] d : dydx) {
            int ny = cur[0] + d[0], nx = cur[1] + d[1];
            
            if (isValidScope(new int[]{ny, nx}) && visited[ny][nx] == 1) {
                return false;
            }
        }
        
        return true;
    }
    
    private boolean isValidScope(int[] cur) {
        return (0 <= cur[0] && cur[0] < N && 0 <= cur[1] && cur[1] < M);
    }
}