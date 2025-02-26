import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = players;
        
        Map<String, Integer> map = new HashMap<>();
        
        for(int i=0; i<players.length; i++) map.put(players[i], i);
        
        for(int i=0; i<callings.length; i++) {
            int rank = map.get(callings[i]);
            String name = answer[rank-1];

            answer[rank-1] = answer[rank];
            answer[rank] = name;
            map.put(answer[rank-1], rank-1);
            map.put(answer[rank], rank);
        }
        
        return answer;
    }
}