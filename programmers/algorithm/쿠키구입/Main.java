class Solution {
    private int N = 0; // 1 <= n <= 2,000
        
    // 무식한 방법: 2,000^3 = 8,000,000,000 (time over)
    // 적어도 O(N^2)로 줄이면 해결 가능. (투 포인터 알고리즘)
    // - mid를 기준으로 left = mid, right = mid+1
    // - leftSum == rightSum이면 ++count
    // - leftSum < rightSum이면, --left -> leftSum += cookie[left]
    // - leftSum > rightSum이면, ++right -> rightSum += cookie[right]
    // - leftSum < rightSum && left == 0 혹은 leftSum > rightSum && right = N-1 이면 mid 이동
    public int solution(int[] cookie) { // 1 <= cookie[i] <= 500
        N = cookie.length;
        int answer = 0;
        
        for (int mid=0; mid<N-1; ++mid) {
            int left = mid, right = mid+1;
            int leftSum = cookie[left], rightSum = cookie[right];
            
            while (true) {
                if (leftSum == rightSum) {
                    answer = Math.max(answer, leftSum);
                }
                
                if (leftSum <= rightSum && left != 0) {
                    leftSum += cookie[--left];
                } else if (leftSum >= rightSum && right != N-1) {
                    rightSum += cookie[++right];
                } else {
                    break;
                }
            }
        }
        
        return answer;
    }
}