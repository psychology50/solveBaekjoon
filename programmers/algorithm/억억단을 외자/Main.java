class Solution {
    // 임의의 수: 1 <= e <= 5,000,000
    // 1 <= start 길이 <= min{e, 100,000}
    // 1 <= start 원소 <= e
    // 반환: start에 대해서 start <= x <= e 중, 억억단에서 가장 많이 등장한 x 반환 (여러 개면 가장 작은 수)
    
    // 1: 1
    // 2: 2, 3, 5, 7, 11, ... (소수)
    // 3: 4, 9, 25, ... (1 * self, 루트(self)만 존재하는 경우)
    // 4: 6, 8, 10, ...
    
    // 각 숫자들의 등장횟수를 구해두는 게 나음
    // 근데,,횟수 구하는 게 N^2/2, 탐색에 필요하는 게 N
    public int[] solution(int e, int[] starts) {
        int answer[] = new int[starts.length];
        
        int[] cache = new int[e+1];
        for (int i=1; i<=e; ++i) for (int j=1; i*j<=e; ++j) ++cache[i*j];
        
        int[] frequency = new int[e+1]; // i번~e 사이 중 최대 빈도수를 보이는 최소값.
        int maxFrequentValue = cache[e];
        int maxFrequentNum = e;
        frequency[e] = e;
        
        for (int i=e-1; i>=1; --i) {
            if (cache[i] >= maxFrequentValue) {
                maxFrequentValue = cache[i];
                maxFrequentNum = i;
            }
            
            frequency[i] = maxFrequentNum;
        }
        
        // for (int i=1; i<=e; ++i) System.out.print(frequency[i] + " ");
        
        for (int i=0; i<starts.length; ++i) {
            int result = frequency[starts[i]];
            
            answer[i] = result;
        }
        
        return answer;
    }
}