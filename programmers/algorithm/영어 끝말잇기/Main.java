import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] failed = new int[2];
        Set<String> usedWord = new HashSet<>();
        usedWord.add(words[0]);
        
        int cur = 2, round = 1;
        
        for (int idx=1; idx<words.length; ++idx) {            
            if (words[idx-1].charAt(words[idx-1].length() - 1) != words[idx].charAt(0) || usedWord.contains(words[idx])) {
                failed[0] = cur;
                failed[1] = round;
                break;
            }
            
            usedWord.add(words[idx]);
            ++cur;
            
            if (cur > n) {
                cur = 1;
                ++round;
            }
        }
        
        return failed;
    }
}