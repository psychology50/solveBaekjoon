class Solution {
    private int N, M;
    private int[][] progress;
    private int[][] target;
    private int answer = 987654321;
    
    // 1 <= N, M <= 10
    // 동전을 뒤집으려면 같은 줄(row or col)을 모두 뒤집어야 함. (0: 앞면, 1: 뒷면)
    // 반환: 최소 뒤집기 횟수 (불가능하면 -1)
    
    // 1 0 1 1 1   x o x o o   1 1 1 0 0   
    // 0 1 0 1 0   o x o x o   1 1 1 1 0   
    // 1 0 0 0 1   x o x o o   1 1 0 1 0   
    // 0 1 0 0 1   o x o x x   1 1 1 0 1   
    // 1 0 1 0 1   x o x o o   1 1 1 1 0   
    // o 홀수, x는 짝수번 뒤집혀야 함. (행/열은 어떻게 선택?)
    
    // 절대 불가능한 경우가 무엇인가?
    // 0 0   o o   1 1
    // 0 0   x o   0 1
    
    // 0 0 0   o x o   1 0 1
    // 0 0 0   x x x   0 0 0
    // 0 0 0   x x x   0 0 0
    
    // 규칙 못 찾겠는데, N 작아서 그냥 무식하게 brute force ㄱㄱ
    // col은 냅두고, row만 보면서 뒤집거나, 뒤집지 않은 경우로 분기 -> col이 모두 같거나, 모두 다르면 어차피 가능함.
    public int solution(int[][] beginning, int[][] target) {
        N = beginning.length;
        M = beginning[0].length;
        
        progress = new int[N][M];
        for (int i=0; i<N; ++i) progress[i] = beginning[i].clone();
        this.target = target;
        
        dfs(0, 0);
        
        return (answer == 987654321) ? -1 : answer;
    }
    
    private void dfs(int row, int cnt) {
        if (row == N) { // 탈출 조건 (가장 아래까지 내려간 경우, 모든 col이 유효한지 확인)
            int matchCnt = matchCoin();
            
            if (matchCnt == -1) return;
            
            answer = Math.min(answer, cnt + matchCnt);
            return;
        }
        
        flipRow(row);
        dfs(row+1, cnt+1); // 뒤집었을 때
        
        flipRow(row);
        dfs(row+1, cnt); // 그냥 지나쳤을 때
    }
    
    // 가능하면 뒤집은 횟수, 불가능하면 -1 반환
    private int matchCoin() {
        int moveCnt = 0;
        
        for (int c=0; c<M; ++c) {
            int differCnt = 0; // 모두 같거나(0), 모두 달라야 함(N)
            
            for (int r=0; r<N; ++r) if (progress[r][c] != target[r][c]) ++differCnt;
            
            if (differCnt == N) ++moveCnt;
            else if (differCnt != 0) return -1; // 모두 다르지도 않으면서, 모두 같지도 않으면 실패
        }       
        
        return moveCnt;
    }
    
    private void flipRow(int row) {
        for (int c=0; c<M; ++c) {
            progress[row][c] = (progress[row][c] == 1) ? 0 : 1; 
        }
    }
}