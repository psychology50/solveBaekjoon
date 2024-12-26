class Solution {
    // 1 <= N <= 500,000
    // 결과: 연속 펄스 부분 수열의 합 중 가장 큰 값
    //  - ex. [2, 3, -6, 1, 3, -1, 2, 4]
    //  - pulse1. [2, -3, -6, -1, 3, 1, 2, -4]
    //  - pulse2. [-2, 3, 6, 1, -3, -1, -2, -4]
    public long solution(int[] sequence) {
        long answer = sequence[0];
        
        int N = sequence.length;

        long[] cache = new long[N];
        cache[0] = sequence[0];
        // System.out.print(cache[0] + " ");
        for (int i=1; i<N; ++i) { // +1, -1, ...
            int cur = (i % 2 == 0) ? sequence[i] : -1 * sequence[i];
            
            cache[i] = Math.max(cur, cache[i-1] + cur);
            // System.out.print(cache[i] + " ");
            answer = Math.max(answer, cache[i]);
        }
        // System.out.println();
        
        answer = Math.max(answer, sequence[0] * -1);
        cache = new long[N];
        cache[0] = -1 * sequence[0];
        System.out.print(cache[0] + " ");
        for (int i=1; i<N; ++i) { // -1, 1, ...
            int cur = (i % 2 == 1) ? sequence[i] : -1 * sequence[i];
            
            cache[i] = Math.max(cur, cache[i-1] + cur);
            // System.out.print(cache[i] + " ");
            answer = Math.max(answer, cache[i]);
        }
        
        return answer;
    }
}