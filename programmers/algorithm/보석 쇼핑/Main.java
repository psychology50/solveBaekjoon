import java.util.*;

class Solution {
    private Map<String, Integer> items = new HashMap<>(); // 아이템, 아이템 번호
    private int itemCnt = 1;

    // 1 <= N <= 100,000
    // return: 진열된 모든 종류의 보석을 적어도 1개 이상 포함하는 가장 짧은 구간 [시작, 끝]
    // (1) 모든 아이템의 번호를 매겨서 전처리 
    // (2) 탐색
    //      - 투 포인터: 아직 모든 아이템을 포함 못 했으면 right 이동, 모두 포함 중이면 left 이동 (최소 범위 탐색)
    public int[] solution(String[] gems) {
        int[] itemNums = convertToInt(gems);
        
        int left = 0, right = 0;
        Map<Integer, Integer> visited = new HashMap<>();
        visited.put(itemNums[0], 1);
        int[] answer = new int[]{-1, 987654321};
        
        while (true) {
            // System.out.println("담은 상품 정보 : " + visited);
            if (visited.size() != itemCnt) { // 아직 모든 아이템을 포함 못한 경우
                if (++right >= itemNums.length) { // 더 이상 이동 불가능한 경우
                    break;
                }
                
                // System.out.println("right 이동 : " + (right+1) + " --> 상품 ID: " + itemNums[right]);
                Integer num = Integer.valueOf(itemNums[right]);
                if (visited.get(num) == null) {
                    visited.put((num), 0);
                }
                visited.put(num, visited.get(num) + 1);
            } else { // 모든 아이템 포함 중이면, left 이동
                if (right - left < answer[1] - answer[0]) { // 새로운 최소 길이를 찾은 경우 업데이트
                    // System.out.println("left = " + (left+1) + ", right = " + (right+1) + " ===> length = " + (right - left));
                    answer[0] = left + 1;
                    answer[1] = right + 1;
                }
                
                // System.out.println("left 이동 : " + (left+1));
                
                Integer num = Integer.valueOf(itemNums[left++]);
                visited.put(num, visited.get(num) - 1);
                if (visited.get(num) == 0) visited.remove(num);
            }
        }
        
        return answer;
    }
    
    private int[] convertToInt(String[] gems) {
        int[] itemNums = new int[gems.length];
        
        for (int i=0; i<gems.length; ++i) {
            if (items.get(gems[i]) == null) {
                items.put(gems[i], Integer.valueOf(itemCnt++));
            }
            itemNums[i] = items.get(gems[i]).intValue();
        }
        --itemCnt; // 실제 아이템 개수로 맞춤.
        
        return itemNums;
    }
}