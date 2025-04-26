class Solution {
    private static final int MAX_VALUE = 1_000_001;
    
    // 1 <= x <= y <= 1,000,000
    // 1<= n < y
    // 최악의 경우? x = n = 1 & y = 1,000,000 -> 가장 무식한 방법은 O(3N)
    public int solution(int x, int y, int n) {
        int[] cache = new int[MAX_VALUE];
        for (int i=x; i<=y; ++i) cache[i] = 987654321;
        cache[x] = 0;
        
        int cnt=-1;
        for (int cur=x; cur<=y; ++cur) if (cache[cur] != 987654321) {
            if (cur + n <= y) cache[cur+n] = Math.min(cache[cur+n], cache[cur]+1);
            if (cur * 2 <= y) cache[cur*2] = Math.min(cache[cur*2], cache[cur]+1);
            if (cur * 3 <= y) cache[cur*3] = Math.min(cache[cur*3], cache[cur]+1);
        }
        
        return (cache[y] == 987654321) ? -1 : cache[y];
    }
}