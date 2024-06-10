import java.util.*;

class Solution {
    private boolean[] visited;
    private List<String> answer = new ArrayList<>();
    
    public String[] solution(String[][] tickets) {
        visited = new boolean[tickets.length];
        
        dfs("ICN", 0, "ICN", tickets);
        
        Collections.sort(answer);
        
        return answer.get(0).split(" ");
    }
    
    private void dfs(String now, int cnt, String route, String[][] tickets) {
        if (cnt == tickets.length) {
            answer.add(route);
            return;
        }
        
        for (int i=0; i<tickets.length; ++i) {
            String from = tickets[i][0], to = tickets[i][1];
            
            if (!now.equals(from) || visited[i]) continue;
            
            visited[i] = true;
            dfs(to, cnt+1, route + " " + to, tickets);
            visited[i] = false;
        }
    }
}