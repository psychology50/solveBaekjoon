class Solution {
    // 스타 수열 조건
    //  - x 길이 2 이상의 짝수
    //  - 길이 2n이면, n개 집합의 교집합의 원소 개수가 1 이상
    //      - ex. [1,2,1,3,4,1,1,3]에서 교집합 {1}이 존재.
    //  - x[2n-2] != x[2n-1]
    // 길이가 가장 긴 스타 수열 반환 (없으면 0)
    // 1 <= N <= 500,000 -> O(N) 혹은 O(NlogN)으로 끝내야 함.
    public int solution(int[] a) {
        int answer = 0;
        int[] mutualNbr = new int[a.length]; // 공통 분모로 사용할 값 (원소 조건에 의해 가능)
        for (int i=0; i<a.length; ++i) ++mutualNbr[a[i]]; // 공통 분모의 등장 횟수        
        
        for (int k=0; k<a.length; ++k) {
            if (mutualNbr[k] <= answer) continue; // 공통 인자의 사용 가능 횟수가 현재 최대 집합 개수보다 작으면 패스
            
            int result = 0;
            for (int i=0; i<a.length-1; ++i) if (a[i] != a[i+1] && (k == a[i] || k == a[i+1])) { // 스타 수열 조건
                ++result;
                ++i;
            }
            
            answer = Math.max(answer, result);
        }
        
        return 2 * answer;
    }
}