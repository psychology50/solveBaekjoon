import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        Map<Integer, Integer> box = new HashMap<>();
        
        for (int t : tangerine) {
            Integer T = Integer.valueOf(t);
            
            if (box.get(T) == null) {
                box.put(T, 1);
            } else {
                box.put(T, box.get(T) + 1);
            }
        }
        
        List<Integer> sum = new ArrayList<>(box.values());
        Collections.sort(sum, Collections.reverseOrder());
        
        int answer = 0;
        int capacity = 0;
        for (int cur: sum) {
            if (capacity + cur >= k) {
                ++answer;
                break;
            } else {
                capacity += cur;
                ++answer;
            }
        }
        
        return answer;
        
    }
}