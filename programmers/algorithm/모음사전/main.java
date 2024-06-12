import java.util.*;

class Solution {
    private String[] words = {"A", "E", "I", "O", "U"};
    private List<String> dictionary = new ArrayList<>();
    
    public int solution(String word) {
        dfs("", 0);
        
        return dictionary.indexOf(word);
    }
    
    private void dfs(String tmp, int depth) {
        dictionary.add(tmp);
        
        if (depth == 5) {
            return;
        }
        
        for (int i=0; i<5; ++i) {
            dfs(tmp + words[i], depth + 1);
        }
    }
}