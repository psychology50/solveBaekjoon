import java.util.*;

class Solution {
    private static final int MOD = 1000000007;
    
    // - 1 <= N <= 100,000
    // 1 <= money.length <= 100
    // 0 ~ N 까지 점프하는 느낌으로 이해하면 쉬울 듯. i번 째 지점에서 목적지에 도달할 수 있는 경우의 수는 몇 개인가?
    // 단, 화폐 사용 순서는 중요하지 않음. 어떤 화폐를 얼마나 사용했냐가 중요함.
    public int solution(int n, int[] money) {
        long[] cache = new long[n+1]; // cache[i개의 가상 화폐] = 지불 가능 금액
        
        Arrays.sort(money);
        
        // 가장 작은 화폐만으로 만들 수 있는 조합 초기화
        for (int i=0; i<=n; ++i) {
            if (i % money[0] == 0) {
                cache[i] = 1;
            } 
        }
        
        for (int num=1; num<money.length; ++num) for (int value=money[num]; value<=n; ++value) {
            cache[value] += cache[value-money[num]] % MOD;
        }
        
        return (int) cache[n];
    }
}