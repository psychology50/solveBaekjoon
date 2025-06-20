import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        int[] corrector = new int[3];
        
        int[] n1 = new int[]{1, 2, 3, 4, 5};
        int[] n2 = new int[]{2, 1, 2, 3, 2, 4, 2, 5};
        int[] n3 = new int[]{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        
        for (int i=0; i<answers.length; ++i) {
            if (n1[i % n1.length] == answers[i]) ++corrector[0];
            if (n2[i % n2.length] == answers[i]) ++corrector[1];
            if (n3[i % n3.length] == answers[i]) ++corrector[2];
        }
        
        List<Integer> result = new ArrayList<>();
        int maxScore = 0;
        for (int i=0; i<3; ++i) if (maxScore < corrector[i]) maxScore = corrector[i];
        for (int i=0; i<3; ++i) if (maxScore == corrector[i]) result.add(i+1);
        
        result.sort((a, b) -> a - b);
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}