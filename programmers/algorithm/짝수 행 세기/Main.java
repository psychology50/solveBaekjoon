

class Solution {
    private static final long MOD = 19 + (long) 10e7;
    
    private int N=0, M=0;
    private int[] colCnt;
    private int answer = 0;
    
    private static long comb[][];
    private static long cache[][];
    
    // 배열 int[][] b 규칙
    // 1. 모든 원소는 0 or 1
    // 2. a와 b의 크기는 동일
    // 3. i = 1, 2, ..., (a 열의 개수)에 대해 a_i번째 열과 b_i번째 열의 1의 개수가 가음.
    // 4. b 각 행의 1의 개수가 짝수 (0도 마찬가지)
    
    // 무식한 방법: 전부 만들기 -> 2 ^ (300 * 300)
    // 백트래킹(dfs): 여전히 너무 많은 연산. -> 최악 300 ^ 300
    public int solution(int[][] a) {      
        if (!init(a)) return 0; // 배열 a의 1의 개수가 짝수가 아닌 경우.
        
        cache[0][colCnt[0]] = combination(N, colCnt[0]);
        
        for (int i=1; i<M; ++i) for (int j=0; j<=N; ++j) {
            if (cache[i-1][j] == 0) {
                continue;
            }
            int cnt = colCnt[i];
            
            for (int numberOfOdd = Math.max(0, cnt - N + j); numberOfOdd <= Math.min(cnt, j); ++numberOfOdd) {
                cache[i][j - numberOfOdd + (cnt - numberOfOdd)] += (cache[i-1][j] * (combination(j, numberOfOdd) * combination(N - j, cnt - numberOfOdd) % MOD)) % MOD;
                cache[i][j - numberOfOdd + (cnt - numberOfOdd)] %= MOD;
            }
        }
        
        return (int)cache[M-1][0];
    }
    
    private boolean init(int[][] a) {
        N = a.length; M = a[0].length;
        colCnt = new int[M];
        
        int total = 0;
         
        for (int i=0; i<M; ++i) for (int j=0; j<N; ++j) {
            if (a[j][i] == 1) {
                ++colCnt[i];
                ++total;
            }
        }
        
        if (total % 2 == 1) return false;
        
        comb = new long[N+1][M+1];
        // comb[0][0] = 1;
        
        cache = new long[M][N+1]; // [col][1의 개수가 홀수인 행의 수]
        
        return true;
    }
    
    // 파스칼 법칙: nCr = (n-1)Cr + (n-1)C(r-1)
    private static long combination(int n, int r) {
        if (comb[n][r] != 0) {
            return comb[n][r];
        }
        
        if (n == r || r == 0) {
            return comb[n][r] = 1;
        }
        
        return comb[n][r] = (combination(n-1, r) + combination(n-1, r-1)) % MOD;
    }
}