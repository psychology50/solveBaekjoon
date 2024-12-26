import java.util.*;

class Solution {
    public String solution(int n, int k, String[] cmd) {
        StringBuilder answer = new StringBuilder("O".repeat(n));
        int cursor = k;
        
        int[][] nodes = new int[n][2]; // {pre 노드 번호, pos 노드 번호}, 원형 리스트로 구현
        for (int i=0; i<n; ++i) {
            nodes[i][0] = i-1;
            nodes[i][1] = i+1;
        }
        nodes[0][0] = n-1;
        nodes[n-1][1] = 0;
        
        Stack<int[]> cache = new Stack<>(); // {pre, cur, pos}
        
        for (String c: cmd) {
            // System.out.println("커맨드 : " + c + " (현재 커서: " + cursor + ")"); // DEBUGGING
            
            if (c.startsWith("D")) {
                int x = Integer.parseInt(c.split(" ")[1]);
                
                while (x-- > 0) cursor = nodes[cursor][1];
                
                // System.out.println("커서 이동: " + cursor + ")"); // DEBUGGING
            }
            
            if (c.startsWith("U")) {
                int x = Integer.parseInt(c.split(" ")[1]);
                
                while (x-- > 0) cursor = nodes[cursor][0];
                
                // System.out.println("커서 이동: " + cursor + ")"); // DEBUGGING
            }
            
            if (c.startsWith("C")) {
                cache.add(new int[]{nodes[cursor][0], cursor, nodes[cursor][1]});
                
                // 앞-뒤 노드 매핑
                nodes[nodes[cursor][0]][1] = nodes[cursor][1]; 
                nodes[nodes[cursor][1]][0] = nodes[cursor][0];
                answer.setCharAt(cursor, 'X');
                
                cursor = (nodes[cursor][1] != 0) ? nodes[cursor][1] : nodes[cursor][0]; // 가장 아래라면, 바로 윗행으로
            }
            
            if (c.startsWith("Z")) {
                int[] memory = cache.pop();
                
                nodes[memory[0]][1] = memory[1];
                nodes[memory[2]][0] = memory[1];
                answer.setCharAt(memory[1], 'O');
            }    
            
            // System.out.println(answer.toString());
        }
        
        return answer.toString();
    }
    
    // 시간 초과: 예상대로 일반 배열은 안 됨. 삭제/추가가 빠른 LinkedList를 사용하되, 조회도 빠르게 연결 정보를 따로 저장해야 함.
//     private List<Integer> origin = new ArrayList<>();
//     private List<Integer> copy = new ArrayList<>();
    
//     // 5 <= n <= 1,000,000 (행 개수)
//     // 0 <= k < n (처음 선택된 행 위치)
//     // 1 <= cmd.length <= 500,000
//     //  - "U X": 현재 선택된 행에서 X칸 위의 행을 선택 (1 <= X <= 300,000)
//     //  - "D X": 현재 선택된 행에서 X칸 아래의 행을 선택
//     //  - "C": 선택된 행 삭제, 바로 아래 행 선택 (가장 밑이면, 바로 윗 행을 선택)
//     //  - "Z": 가장 최근에 삭제된 행을 복구. (현재 선택된 행은 유지; 복구할 행이 없을 때 이 명령어를 수행하는 경우는 없음)
//     //      - 만약 5번 인덱스를 복구하는데, 현재 행 길이가 3밖에 안 된다면?
//     // 결과: 처음 표와 비교하여, 삭제되지 않은 행은 O, 삭제된 행은 X로 표시한 문자열 반환
//     public String solution(int n, int k, String[] cmd) {
//         for (int i=0; i<n; ++i) {
//             origin.add(i);
//             copy.add(i);
//         }
        
//         Stack<int[]> cache = new Stack<>();
//         int cursor = k;
        
//         for (String c: cmd) {
//             // System.out.println("커맨드 : " + c + " (현재 커서: " + cursor + ")"); // DEBUGGING
            
//             if (c.startsWith("D")) {
//                 int x = Integer.parseInt(c.split(" ")[1]) % copy.size();
            
//                 if (cursor + x >= copy.size()) {
//                     cursor = x - (copy.size() - cursor - 1) - 1;
//                 } else {
//                     cursor += x;
//                 }
                
//                 // System.out.println("커서 이동: " + cursor + ")"); // DEBUGGING
//             }
            
//             if (c.startsWith("U")) {
//                 int x = Integer.parseInt(c.split(" ")[1]) % copy.size();
                
//                 if (cursor - x < 0) {
//                     cursor = copy.size() - (x - cursor);
//                 } else {
//                     cursor -= x;
//                 }
                
//                 // System.out.println("커서 이동: " + cursor + ")"); // DEBUGGING
//             }
            
//             if (c.startsWith("C")) {
//                 int[] memory = new int[]{cursor, copy.get(cursor)};
//                 cache.add(memory);
                
//                 copy.remove(cursor);
                
//                 if (cursor >= copy.size()) --cursor; // 마지막 행이면, 바로 윗 행으로 이동
//             }
            
//             if (c.startsWith("Z")) {
//                 if (cursor >= copy.size()) {
//                     int[] memory = cache.pop();
//                     copy.add(memory[1]);
//                 } else {
//                     int[] memory = cache.pop();
//                     copy.add(memory[0], memory[1]);
                    
//                     if (cursor >= memory[0]) ++cursor; // 추가된 행이 위에 있으면, 커서 한 칸 아래로
//                 }
//             }
            
//             // System.out.println(copy);
//         }
        
//         return compareOriginAndCopy(n);
//     }
    
//     private String compareOriginAndCopy(int n) {
//         StringBuilder sb = new StringBuilder();
        
//         int originCursor = 0, copyCursor = 0;
//         while (originCursor < n) {
//             if (origin.get(originCursor).equals(copy.get(copyCursor))) {
//                 sb.append("O");
//                 ++originCursor;
//                 ++copyCursor;
//             } else {
//                 sb.append("X");
//                 ++originCursor;
//             }
//         }

//         return sb.toString();
//     }
}