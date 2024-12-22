class Solution {
    // 1 <= N, M <= 1,000
    // 1 <= board[y][x] <= 1,000
    // skill[idx][type, r1, c1, r2, c2, degree] 
    //  - 1 <= idx <= 250,000
    //  - type: 1(공격), 2(힐)
    //  - (r1, c1) ~ (r2, c2): 범위 (단, r2, c2는 언제나 r1, c1보다 같거나 큼)
    //  - degree: 스킬 정도 (1 <= degree <= 100)
    // 건물이 1 이상의 값을 가지면 파괴되지 X
    // 반환: 파괴되지 않은 건물 개수
    
    // 무식한 방법 (최악): R(250,000) * NM + NM = O(NMR) ~= 250,000,000,000
    //  - R을 스캔 안 할 수는 없음. NM도 한 번은 읽어야함. 하지만 매번 업데이트는 안 됨.
    //  - R 정보를 재구성할 수는 없을까?
    //  - R만큼 반복 -> 좌표마다 누적치 계산 -> NM 순회하면서 누적치 더하면서 1미만 값 카운트
    //      - 1,000 * 1,000 개의 키 값. -> 반복이 들어가는 것도 동일
    //  - 누적합: [row][col] = 더할 값
    //      - (1) [r1][c1] = degree
    //      - (2) [r2+1][c1] = [r1][c2+1] = -degree
    //      - (3) [r2+1][c2+1] = degree
    public int solution(int[][] board, int[][] skill) {
        int N = board.length;
        int M = board[0].length;
        int[][] total = new int[N][M];
        
        for (int[] s : skill) {
            int type = s[0];
            int r1 = s[1], c1 = s[2];
            int r2 = s[3], c2 = s[4];
            int degree = (type == 1) ? (-1 * s[5]) : s[5];
            
            total[r1][c1] += degree;
            
            if (r2 + 1 < N) total[r2+1][c1] -= degree; // 아래
            if (c2 + 1 < M) total[r1][c2+1] -= degree; // 오른쪽
            if (r2 + 1 < N && c2 + 1 < M) total[r2+1][c2+1] += degree; // 대각선 아래
        }
        
        // 세로 누적합
        for (int r=1; r<N; ++r) for (int c=0; c<M; ++c) {
            total[r][c] += total[r-1][c];
        }
        
        // 가로 누적합
        for (int r=0; r<N; ++r) for (int c=1; c<M; ++c) {
            total[r][c] += total[r][c-1];
        }
        
        int answer = 0;
        for (int r=0; r<N; ++r) for (int c=0; c<M; ++c) {
            if (board[r][c] + total[r][c] >= 1) ++answer;
        }
        
        
        return answer;
    }
}