import java.util.*;

class Solution {
    public int solution(int[] elements) {
        int n = elements.length;
        int[] tmp = new int[n*2];
        Set<Integer> result = new HashSet<>();
        
        for (int i=0; i<n; ++i) tmp[i] = tmp[i+n] = elements[i];
        for (int cur=n; cur<2*n; ++cur) {
            int total = tmp[cur];
            
            result.add(total);
            
            for (int j=1; j<n; ++j) {
                total += tmp[cur-j];
                result.add(total);
            }
        }
        
        return result.size();
    }
}