import java.util.*;

class Solution {
    private int N = 0;
    private int M = 0;
    
    // 모든 행을 조각내면? 좌우 & 가운데 각 row들을 별도로 관리
    public int[][] solution(int[][] rc, String[] operations) {
        N = rc.length;
        M = rc[0].length;
        
        Deque<Integer> leftCol = new ArrayDeque<>();
        Deque<Integer> rightCol = new ArrayDeque<>();
        Deque<ArrayDeque<Integer>> rows = new ArrayDeque<>();
        
        for (int r=0; r<N; ++r) {
            leftCol.add(rc[r][0]);
            rightCol.add(rc[r][M-1]);
            
            ArrayDeque<Integer> row = new ArrayDeque<>();
            for (int c=1; c<M-1; ++c) row.add(rc[r][c]);
            rows.add(row);
        }
        
        for (String oper : operations) {
            if (oper.equals("ShiftRow")) {
                leftCol.addFirst(leftCol.removeLast());
                rightCol.addFirst(rightCol.removeLast());
                rows.addFirst(rows.removeLast());
            } else {
                rows.getFirst().addFirst(leftCol.removeFirst());
                rightCol.addFirst(rows.getFirst().removeLast());
                rows.getLast().addLast(rightCol.removeLast());
                leftCol.addLast(rows.getLast().removeFirst());
            }
        }
        
        int[][] answer = new int[N][M];
        for (int r=0; r<N; ++r) {
            answer[r][0] = leftCol.removeFirst();
            answer[r][M-1] = rightCol.removeFirst();
            
            Deque<Integer> row = rows.removeFirst();
            for (int c=1; c<M-1; ++c) {
                answer[r][c] = row.removeFirst();
            }
        }
        
        return answer;
    }
    
    // 시간 초과
//     // ShiftRow: 모든 행을 아래로 한 칸 이동
//     // Rotate: 행렬의 바깥쪽 원소들을 시계 방향으로 한 칸 이동
//     // 2 <= r, c <= 50,000
//     // 4 <= r * c <= 100,000
//     // 1 <= rc[i][j] <= 1,000,000
//     // 1 <= operation.length <= 100,000
//     public int[][] solution(int[][] rc, String[] operations) {
//         N = rc.length;
//         M = rc[0].length;
//         int[][] answer = new int[N][M];
//         for (int i=0; i<N; ++i) answer = rc.clone();

//         for (String oper : operations) {
//             if (oper.equals("ShiftRow")) {
//                 shiftRow(answer);
//             } else {
//                 rotate(answer);
//             }
//         }
        
//         return answer;
//     }
    
//     private void shiftRow(int[][] rc) {
//         int[] lastRow = rc[N-1];
        
//         for (int i=N-1; i>0; --i) {
//             rc[i] = rc[i-1];
//         }
        
//         rc[0] = lastRow;
//     }
    
//     private void rotate(int[][] rc) {
//         int r0cl = rc[0][M-1];
//         int rlc0 = rc[N-1][0];
        
//         for (int c=0; c<M-1; ++c) {
//             rc[0][M-1-c] = rc[0][M-c-2]; 
//             rc[N-1][c] = rc[N-1][c+1];
//         }
        
//         for (int r=0; r<N-2; ++r) {
//             rc[r][0] = rc[r+1][0];
//             rc[N-1-r][M-1] = rc[N-r-2][M-1];
//         }
        
//         rc[1][M-1] = r0cl;
//         rc[N-2][0] = rlc0;
//     }
}