import java.util.regex.*;
import java.util.*;

class Solution {
    private static final String REGX = "([0-9]+)([SDT])([*#]?)";
    private static final Pattern pattern = Pattern.compile(REGX + REGX + REGX);
    private static final Map<String, Integer> darts = Map.of("S", 1, "D", 2, "T", 3);
    private static final Map<String, Integer> options = Map.of("*", 2, "#", -1);
    
    private int[] result = new int[3];
    
    public int solution(String dartResult) {
        int answer = 0;
        
        Matcher matcher = pattern.matcher(dartResult);
        matcher.matches();
        
        int count = 0;
        for (int i=1; i<matcher.groupCount(); i+=3) {
            int point = Integer.parseInt(matcher.group(i));
            int bonus = darts.get(matcher.group(i+1));
            int option = (!matcher.group(i+2).isBlank()) ? options.get(matcher.group(i+2)) : 1;
            
            result[count] = (int)Math.pow(point, bonus) * option;
            System.out.println(result[count]);
            if (count != 0 && option == 2)
                result[count-1] *= option;
            ++count;
        }
        
        return result[0] + result[1] + result[2];
    }
}