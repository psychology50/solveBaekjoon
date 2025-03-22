import java.util.*;

class Solution {
    private Queue<int[]> q = new PriorityQueue<>((a, b) -> ((a[1] - a[0]) == (b[1] - b[0])) ? a[0] - b[0] : (a[1] - a[0]) - (b[1] - b[0]));
    
    // sequence(비내림차순 = 오름차순) : 5 <= len <= 1,000,000 (1 <= e <= 1,000)
    // 부분 수열 찾기
    //  - 기존 수열 내 임의 두 인덱스 원소, 그 사이 원소를 모두 포함하는 부분 수열
    //  - k = 부분 수열 합 (5 <= k <= 1,000,000,000)
    //  - 값이 여러 개라면 짧은 수열
    //  - 길이가 같은 게 여러 개면 인덱스 작은 거
    public int[] solution(int[] sequence, int k) {
        int total = sequence[0];
        int left = 0, right = 0;
        while (true) {
            if (total == k) q.add(new int[]{left, right});
            
            if (left == right || total < k) {
                if (++right == sequence.length) break;
                
                total += sequence[right];
            } else if (total >= k) {
                total -= sequence[left++];
            }
        }
        
        return q.peek();
    }
}