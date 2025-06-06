import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        int[] answer = {-1};
        List<Integer> answ = new ArrayList<Integer>();
        
        for(int num : arr) {
            if(num % divisor == 0) answ.add(num);
        }
        
        if(answ.size() != 0) {
            answer = new int[answ.size()];

            for(int i=0; i<answ.size(); i++){
                answer[i] = answ.get(i);
            }

            Arrays.sort(answer);  
        }
        
        return answer;
    }
}