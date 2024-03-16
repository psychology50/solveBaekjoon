// @author 21911407 양재서
import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int n = numbers.length;
        Set<Integer> set = new HashSet<>();
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            set.add(numbers[i] + numbers[j]);
        }
        
        int[] answer = new int[set.size()];
        int i = -1;
        for (Integer s : set) answer[++i] = s;
        Arrays.sort(answer);
        return answer;
    }
}