import java.util.*;

// 배열 우측 90도 회전식: (x, y) = (N-y-1, x)
class Solution {
    private int[][] target;
    private int lockHomeCnt;
    private int n, m;
    
    private List<int[]> keyPoints = new ArrayList<>();
    
    // 자물쇠: N * N (3 <= N <= 20)
    // 열쇠: M * M (3 < M <= N)
    // 회전과 이동이 가능 (영역 밖으로 돌기가 벗어날 수도 있음.)
    // 반환 반환 열쇠로 자물쇠 열 수 있는지? (자물쇠 영역 내에서 자물쇠 홈 - 열쇠 돌기가 완벽히 일치)
    // N, M이 작아도 무식하게 해도 될 거 같은데?
    // - Lock의 홈을 기준으로 만들어야 하는 target 배열 생성
    //  - Lock 홈 개수 > key 돌기 개수 : 불가능
    //  - target 불필요한 영역을 잘라내도 key의 영역보다 크다면 : 불가능
    public boolean solution(int[][] key, int[][] lock) {
        n = lock.length;
        m = key.length;
        for (int r=0; r<n; ++r) for (int c=0; c<n; ++c) if (lock[r][c] == 0) {
            ++lockHomeCnt;
        }
        
        for (int r=0; r<m; ++r) for (int c=0; c<m; ++c) if (key[r][c] == 1) {
            keyPoints.add(new int[]{r, c});
        }

        for (int i=0; i<4; ++i) {
            if (i > 0) rotate(); // 90도 씩 회전시키기
            
            for (int ny=-n-1; ny<n; ++ny) for (int nx=-n-1; nx<n; ++nx) { // 각 요소들을 ny, nx씩 이동하면서 비교
                if (isMatch(ny, nx, lock)) return true;
            }
        }
        
        return false;
    }
    
    private void rotate() {
        List<int[]> rotatedKeyPoints = new ArrayList<>();
        
        for (int[] point : keyPoints) {
            rotatedKeyPoints.add(new int[]{m-point[1]-1, point[0]});
        }
        
        keyPoints = rotatedKeyPoints;
    }
    
    // 매칭해보고 안 되면, 90도 회전 3번 추가
    private boolean isMatch(int ny, int nx, int[][] target) {
        int cnt = 0;
        
        for (int[] point : keyPoints) {
            int y = point[0] + ny, x = point[1] + nx;
            
            if (0 <= y && y < n && 0 <= x && x < n) {
                if (target[y][x] == 0) {
                    ++cnt;
                } else {
                    return false;
                }
            }
        }
        
        return (cnt == lockHomeCnt) ? true : false;
    }
}