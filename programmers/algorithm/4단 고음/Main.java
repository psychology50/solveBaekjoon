class Solution {
    private long N = 0;
    private int answer = 0;
    
    // 입력: 5 <= n <= 2^31 - 1 (최종 음높이)
    // 출력: 서로 다른 3단 고음 문자열 개수
    // 3단 고음 종류
    //  (1) 3단 고음: *++
    //  (2) 3단 고음 후 다시 3단 고음: *++*++ ((cur * 3 + 2) * 3 + 2)
    //  (3) 3단 고음 중 다시 3단 고음: *+*+++ ((cur * 3 + 1) * 3 + 3)
    //
    // 최적화를 어떻게 할 것인가? 
    // <<f_max(k) = 3단 고음이 k개일 때, 최대 음 높이>>
    // f_max(1) = 3 + 2 = 5  --> (3^1 + 2) --> (3^1 + 3^1 - 1)
    // f_max(2) = f(1)*3 + 2 = 17 --> (3^2 + 8) --> (3^2 + 3^2 - 1)
    // f_max(3) = f(2)*3 + 2 = 53 --> (3^3 + 26) --> (3^3 + 3^3 - 1)
    // f_max(4) = f(3)*3 + 2 = 161 --> (3^4 + 80) --> (3^4 + 3^4 - 1)
    // f_max(k) = f(k-1)*3 + 2 = 2*(3^k) - 1
    // <<f_min(k) = 3단 고음이 k개일 때, 최소 음 높이>>
    // f_min(1) = 3 + 2 = 5
    // f_min(2) = 3^2 + 2^2 = 13
    // f_min(k) = 3^k + 2^k
    // 따라서, 3^k + 2^k <= x(최종 음 높이 n에서 필요한 3단 고음 개수) <= 2*(3^k) - 1
    // 이 때, x를 결정하는 지배값은 x = 3^k, 따라서 k = log(x)/log(3)
    public int solution(int n) {
        int remainMul = (int)(Math.log(n) / Math.log(3));
        
        return dfs(n - 2, remainMul, 2 * remainMul - 2);
    }
    
    private int dfs(int cur, int remainMul, int remainPlus) {
        if (remainMul * 2 < remainPlus) return 0; // 남은 * 개수보다 +가 너무 많은 경우, 조합 실패
        if (remainMul == 1) { // 기저 사례
            if (cur == 3 && remainPlus == 0) return 1; // *
            if (cur == 4 && remainPlus == 1) return 1; // *+
            if (cur == 5 && remainPlus == 2) return 1; // *++
        }
        
        int cnt = 0;
        for (int i=0; i<=remainPlus; ++i) {
            if (cur-i > 0 && (cur-i) % 3 == 0) { // 현재 수를 3으로 나눌 수 있다면
                cnt += dfs((cur-i)/3, remainMul - 1, remainPlus - i);
            }
        }
        
        return cnt;
    }
    
//     // 시작: 3단 고음 (cur = 5)
//     // 다음 (분기점):
//     //  (1) 이어서: cur * 3 + 2
//     //  (2) 도중에: (cur - 1) * 3 + 3
//     // 끝: cur이 n보다 크거나 같으면 종료
//     // 이슈1: StackOverflow -> cur overflow로 인해 문제가 되지 않을까
//     // 이슈2: 1단계 마치자마자 3단 고음을 하는 경우도 존재함.
//     // 이슈3: 꼬리(+)가 몇 개인지 파악해야 함. 
//     //      - 예를 들어, *+*+++에서 1단계 직후 고음을 하면 *+**+++++가 됨
//     //      - 즉, *+*+++ (cur)에서 (cur - 2) * 3 + 4가 아니라, (cur - tail) * 3 + (2 + tail)이 됨. 
//     // 이슈4: n이 정수 최대값일 때 결과가 0 -> + 위치 어디든지 3단 고음이 연결될 수 있다면..? -> 맞는 거 같긴 한데, 무식하게 하면 시간 초과
//     private void dfs(long cur, long tail) {
//         if (cur >= N) {
//             if (cur == N) ++answer;
//             return;
//         }
        
//         for (long nxtStartIdx=0; nxtStartIdx<=tail; ++nxtStartIdx) {
//             dfs((cur - (tail - nxtStartIdx)) * 3 + 2 + (tail - nxtStartIdx), 2 + (tail - nxtStartIdx));
//         }
//     }
}