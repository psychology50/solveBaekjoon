import java.util.*;

class Solution {
    // 두 도둑 A, B 흔척 최소화
    // A info[i][0]개, B info[i][1]개 흔적 남김 (1 <= info[i][] <= 3) (1 <= info <= 30)
    // A 흔적 n개, B 흔적 m개면 잡힘
    // 결과: 두 도둑 안 잡히면서, A 흔적 누적 개수 최솟값 (불가능하면 -1)
    
    public int solution(int[][] info, int n, int m) {
        int[][] cache = new int[info.length + 1][m];
        
        for (int i=1; i<=info.length; ++i) Arrays.fill(cache[i], n);
        cache[0][0] = 0;
        
        for (int i=1; i<=info.length; ++i) {
            int a = info[i - 1][0], b = info[i - 1][1];
            
            for (int j=0; j<m; ++j) {
                // A가 훔치면?
                cache[i][j] = Math.min(cache[i][j], cache[i-1][j] + a);
                
                // B가 훔치면?
                if (j + b < m) {
                    cache[i][j + b] = Math.min(cache[i][j + b], cache[i-1][j]);
                }
            }
        }
        
        int answer = n;
        for (int j=0; j<m; ++j) answer = Math.min(answer, cache[info.length][j]);
        
        return answer >= n ? -1 : answer;
    }
    
    // A 큰 순서 정렬 -> B
    // 그리디: 최적해 보장을 못함 (m 4일 때, b가 (3, 3)일 때보다, (2, 2) (2, 2)를 택할 수 없음.)
//     public int solution(int[][] info, int n, int m) {
//         Arrays.sort(info, (a, b) -> {
//             if (a[0] == b[0]) return a[1] - b[1];
//             return b[0] - a[0];
//         });
        
//         // for (int[] i: info) {
//         //     System.out.println("{" + i[0] + ", " + i[1] + "}");
//         // }
        
//         int a = 0, b = 0;
//         for (int[] i: info) {
//             if (b + i[1] < m) {
//                 b += i[1];
//             } else {
//                 if (a + i[0] < n) {
//                     a += i[0];
//                 } else return -1;
//             }
//         }
        
//         return a;
//     }
}