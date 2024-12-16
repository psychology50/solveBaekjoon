class Solution {
    // private int[][] cache = new int[100001][2];
    // private int[] answer = {Integer.MAX_VALUE, Integer.MAX_VALUE};
    
    // 점수 1~20
    // 싱글(x1), 더블(x2), 트리플(x3), 불(50점)
    // 가장 먼저 0을 만들거나, 같은 라운드에 0을 만들면 "싱글" "볼"을 더 많이 던진 경우 승
    // 1 <= N <= 100,000
    // 반환: 최소한의 다트로 {던진 다트수, 싱글/볼 던진 횟수}
    // 최소한의 다트 : 15점이면 1점 15개나 3점 트리플보단 15점 싱글을 맞춰야 함. 21점이면 20 + 1보다 7 트리플
    // 현재 1~20 혹은 50점 남으면 반드시 single, 그 외에는 한 번에 끝낼 수 있는 경우가 최선
    // 23은? 20 + 3 single이 최선.
    public int[] solution(int target) {
        int[][] cache = new int[target+1][2];
        for (int i=0; i<=target; ++i) {
            cache[i][0] = Integer.MAX_VALUE;
            cache[i][1] = 0;
        }
        cache[0][0]= 0;
        
        for (int cur=1; cur<=target; ++cur) for (int point=1; point<=20; ++point) {
            if (cur-50 >= 0) { // 불을 쏜 경우
                if (cache[cur][0] > cache[cur-50][0]+1) { // 이동 횟수 더 적다면 업데이트
                    cache[cur][0] = cache[cur-50][0] + 1;
                    cache[cur][1] = cache[cur-50][1] + 1;
                } else if (cache[cur][0] == cache[cur-50][0] + 1) { // 이동 횟수 같으면, 싱글/불 많이 쏜 걸로 업데이트
                    cache[cur][1] = Math.max(cache[cur][1], cache[cur-50][1] + 1);
                }
            }
            
            for (int bonus=1; bonus<=3; ++bonus) if (cur - bonus * point >= 0) {
                if (cache[cur][0] > cache[cur - bonus * point][0] + 1) {
                    cache[cur][0] = cache[cur - bonus * point][0] + 1;
                    
                    int singleOrBull = 0;
                    if (bonus == 1) singleOrBull = 1;
                    
                    cache[cur][1] = cache[cur - bonus * point][1] + singleOrBull;
                } else if (bonus == 1 && cache[cur][0] == cache[cur - point][0] + 1) {
                    cache[cur][1] = Math.max(cache[cur][1], cache[cur - point][1]+1);
                }
            }
        }
        
        return cache[target];
    }
    
//     private int[] dfs(int cur, int cnt, int single) {
//         if (cache[cur][0] != 0) {
//             return cache[cur];
//         }
        
//         int[] result = new int[2];
        
        
//         return result;
//     }
}