import java.util.*;
import java.util.stream.Collectors;

class Solution {
    // private List<List<Integer>> candidates = new ArrayList<>();
    // private int N = 0;
    // private int S = 0;
    
    // 최고의 집합: 자연수 n개로 이루어진 중복 집합 중 아래 두 가지 조건을 충족
    //  - 각 원소 합이 S
    //  - 각 원소의 곱이 최대
    // 1 <= n <= 10,000
    // 1 <= s <= 100,000,000
    // 반환: 오름차순 정렬된 1차원 배열 -> 존재하지 않으면 -1로 채울 것
    
    // 실수: 재귀 함수가 n이 아니라 s^2 만큼 실행됨.
    // 개선
    //  - S를 만들기 위한 N개의 원소를 고르는 방법?
    //      - s/n으로 나눈 후, 역산으로 s가 만들어지면 모든 원소를 동일하게 배치 
    //          - ex. 9/3 = 3 -> 3개 원소는 모두 3
    //          - ex. 
    //      - 만약, 역산을 했을 때 차액이 남는다면, 모든 원소에 1씩 배분
    //  - 크기가 동일한 수열의 곱을 최대로 만들려면? => 수열이 최대한 균등하게 분포해야 함. 
    public int[] solution(int n, int s) {
        if (n > s) {
            int[] exception = {-1};
            return exception;
        }
        
        int[] answer = new int[n];
        int quotient = s/n;
        for (int i=0; i<n; ++i) {
            answer[i] = quotient;
        }
        
        if (quotient * n != s) {
            int reminder = s % n;
            
            for (int i=n-1; i>=0 && reminder > 0; --i) {
                ++answer[i];
                --reminder;
            }
        }
        
        return answer;
    }
    
//     private void recur(int depth, int sum, int[] arr) {
//         if (depth == N) {
//             if (sum == S) {
//                 candidates.add(Arrays.stream(arr).boxed().collect(Collectors.toList()));
//             }
            
//             return;
//         }
        
//         for (int i=1; sum + i <= S; ++i) {
//             arr[depth] = i;
//             recur(depth+1, sum+i, arr);
//         }
//     }
    
//     private int[] getBestSet() {
//         int maxValue = -1, maxIndex = 0;
        
//         for (int i=0; i<candidates.size(); ++i) {
//             int multiplValue = calcMuliplyAllElements(candidates.get(i));

//             if (multiplValue > maxValue) {
//                 maxValue = multiplValue;
//                 maxIndex = i;
//             }
//         }
        
//         // <debug>
//         if (maxValue == -1) return null;
        
//         List<Integer> maxSet = candidates.get(maxIndex);
//         Collections.sort(maxSet);
        
//         int[] result = new int[N];
//         for (int i=0; i<N; ++i) {
//             result[i] = maxSet.get(i);
//         }
        
//         return result;
//     }
    
//     private int calcMuliplyAllElements(List<Integer> arr) {
//         int result = 1;
        
//         for (Integer elem : arr) {
//             result *= elem;
//         }
        
//         return result;
//     }
} 