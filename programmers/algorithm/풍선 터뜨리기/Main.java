import java.util.*;

class Solution {
    private static int N = 0;
    
    private Set<Integer> arrive = new HashSet();
    
    // 1 <= N <= 1,000,000
    // -1,000,000,000 <= a[i] <= 1,000,000,000 (정수, 중복 X)
    // (1) 무식한 방법: time-out
    // (2) 투 포인터 : 중간부터 시작하면 꼬임 9, -1, -5
    // (3) 현재 선택한 풍선을 살릴 수 있는가?
    //     - 좌, 우 모두 나보다 크거나, 한 번만 작다면 살 수 있음.
    //     - N 순회하면서, N 반복 시 타임아웃.
    //     - 왼쪽 최소, 오른쪽 최소를 결정해야 함. 
    //     - 한 쪽에 i번 째 값보다 작은 수가 여러 개라면? => 자기네들끼리 경쟁시키면 됨.
    public int solution(int[] a) {
        N = a.length;
        if (N == 1) return 1;
        
        int[] leftMinBalloon = new int[N];
        int[] rightMinBalloon = new int[N];
        
        leftMinBalloon[0] = a[0];
        for (int i=1; i<N; ++i) leftMinBalloon[i] = Math.min(a[i], leftMinBalloon[i-1]);
        
        rightMinBalloon[N-1] = a[N-1];
        for (int i=N-2; i>=0; --i) rightMinBalloon[i] = Math.min(a[i], rightMinBalloon[i+1]);
        
        int nonSaveCnt = 0;
        for (int i=0; i<N; ++i) 
            if (leftMinBalloon[i] < a[i] && rightMinBalloon[i] < a[i]) // 양쪽 모두 나보다 작으면 살릴 수 없음.
                ++nonSaveCnt;
        
        return N - nonSaveCnt;
    }
}