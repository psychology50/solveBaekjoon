import java.util.*;

class Solution {
    private int N, M;
    private String[] userIds;
    private String[] bannedIds;
    private Set<Integer> result = new HashSet<>();
    
    // user_id: 이벤트 응모자 아이디 목록 (1 <= N <= 8, 중복X, 알파벳 소문자 + 숫자)
    // banned_id: 제재 아이디 (1 <= M <= N, 적어도 하나의 * 포함, 중복X)
    // 반환: 당첨에서 제외되어야 할 제제 아이디 목록 경우의 수
    // banned_id 각 요소의 매치 가능한 조합을 구하고, 결과 곱하기 (단, 각 요소는 적어도 하나의 user_id에 매칭되어야 함.)
    public int solution(String[] user_id, String[] banned_id) {
        N = user_id.length;
        M = banned_id.length;
        
        userIds = new String[N];
        userIds = user_id.clone();
        bannedIds = new String[M];
        bannedIds = banned_id.clone();

        boolean[] visited = new boolean[N];
        dfs(0, visited);
        
        return result.size();    
    }
    
    private void dfs(int depth, boolean[] visited) {
        if (depth == M) { // aa, ab, ac, be /
            if (isValid(visited)) {
                // System.out.print("✅ 선택된 값 = ");
                // for (int i=0; i<N; ++i) if (visited[i]) System.out.print(userIds[i] + ", ");
                // System.out.println();
             
                saveHash(visited);
            } 
            // else {
            //     System.out.print("❌ 중복 값 = ");
            //     for (int i=0; i<N; ++i) if (visited[i]) System.out.print(userIds[i] + ", ");
            //     System.out.println();
            // }
            
            return;
        }
        
        for (int i=0; i<N; ++i) if (!visited[i] && isMatch(userIds[i], bannedIds[depth])) {
            visited[i] = true;
            dfs(depth+1, visited);
            visited[i] = false;
        }
    } 
    
    private boolean isMatch(String str, String target) {
        if (str.length() != target.length()) return false;
        
        int i=0;
        while (i < str.length()) {
            if (target.charAt(i) != '*' && str.charAt(i) != target.charAt(i)) {
                return false;
            } 
            ++i;
        }
        
        return true;
    }
    
    private void saveHash(boolean[] visited) {
        int hashValue = makeHash(visited);
        
        result.add(hashValue);
    }
    
    private boolean isValid(boolean[] visited) {
        int hashValue = makeHash(visited);
        // System.out.println("hashCode = " + hashValue);
        
        return !result.contains(hashValue);
    }
    
    private int makeHash(boolean[] visited) {
        int hashValue = 0;
        
        // for (int i=0; i<N; ++i) if (visited[i]) {
        //     if (hashValue == 0) hashValue = Integer.hashCode(i);
        //     else hashValue += 31 * Integer.hashCode(i);
        // }
        
        for (int i=0; i<N; ++i) {
            hashValue <<= i;
            
            if (visited[i]) hashValue += 1;
        }
            
        return hashValue;
    }
}