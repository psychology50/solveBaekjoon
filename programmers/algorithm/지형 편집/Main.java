public class Solution {
    // N * N 크기 지역 (1 <= N <= 300)
    // 0 <= 지형 높이 <= 10억
    // 추가 비용 (1 <= P <= 100), 제거 비용 (Q)
    // 반환: 모든 지형을 동일하게 맞추는 최소 비용
    
    // 300 * 300 순회 하면서, min -> max 만큼 반복하면, 최악 300 * 300 * 10억
    // 이분 탐색
    // int로 계산하니까 자꾸 에러나는 듯
    public long solution(int[][] land, int P, int Q) {
        long left = Long.MAX_VALUE, right = Long.MIN_VALUE;
        
        for (int i=0; i<land.length; ++i) for (int j=0; j<land[0].length; ++j) {
            left = Math.min(left, land[i][j]);
            right = Math.max(right, land[i][j]);
        }
        
        if (left == right) return 0;
        
        long answer = 0;
        while (left <= right) {
            long mid = (left + right) / 2;
            // System.out.println("left = " + left + ", right = " + right + " => mid = " + mid);
            
            // P, Q 분기 처리 대신, 둘 다 계산해서 방향 지정
            long leftCost = getCost(land, mid, P, Q); 
            long rightCost = getCost(land, mid+1, P, Q); 
            // System.out.println("cost = " + cost);
            
            if (leftCost > rightCost) {
                answer = rightCost;
                left = mid + 1;
            } else {
                answer = leftCost;
                right = mid - 1;
            }
        }
        
        return answer;
    }
    
    private long getCost(int[][] land, long height, int P, int Q) {
        long result = 0;
        
        for (int i=0; i<land.length; ++i) for (int j=0; j<land[0].length; ++j) {
            if (land[i][j] < height) result += (height - land[i][j]) * P;
            else result += (land[i][j] - height) * Q;
        }
        
        return result;
    }
}