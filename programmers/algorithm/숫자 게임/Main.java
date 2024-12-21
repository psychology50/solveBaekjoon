import java.util.*;

class Solution {
    // 1 <= N <= 100,000 (A, B 길이는 동일)
    // 1 <= A[i], B[i] <= 1,000,000,000 
    // A는 출전 순서 고정 -> B가 얻을 수 있는 최대 승점 계산 (동점은 점수 X)
    // 둘 다 정렬하고 비교? but, 일부로 한 판 져주고, 점수 얻어갈 수도 있음.
    // ex) A {4,3,2,1} 이면, B {1,4,3,2}로 3점 획득 가능.
    // DP로 해결이 안 됨. A 정렬 유지시킬 이유가 없음 -> 투 포인터로 처리?
    public int solution(int[] A, int[] B) {
        int left = 0;
        int right = B.length-1;
        
        Arrays.sort(A);
        Arrays.sort(B);
        
        int answer = 0;
        for (int i=A.length-1; i>=0; --i) {
            if (B[right] > A[i]) {
                ++answer;
                --right;
            } else {
                ++left;
            }
        }
        
        return answer;
    }
}