import java.util.*;

class Solution {
    private static final String plus = "+";
    private static final String minus = "-";
    
    private static final int maxValue = 987654321;
    private static final int minValue = -987654321;
    
    private int[][] minSum, maxSum;
    private int[] nbrs;
    
    public int solution(String arr[]) {
        int sz = arr.length/2 + 1;
        minSum = new int[sz][sz];
        maxSum = new int[sz][sz];
        
        nbrs = new int[sz];
        
        for (int i=0, j=-1; i<arr.length; i+=2) {
            int nbr = Integer.parseInt(arr[i]);
            
            if (i == 0) {
                nbrs[++j] = nbr;
            } else {
                nbrs[++j] = (arr[i-1].equals(plus)) ? nbr : -nbr; 
            }
        }
        
        for (int l=sz-1; l>=0; --l) for (int r=l; r<sz; ++r) {
            if (l==r) {
                minSum[l][r] = maxSum[l][r] = nbrs[l];
                continue;
            }
            
            minSum[l][r] = maxValue;
            maxSum[l][r] = minValue;
            
            for (int k=l; k<r; ++k) {
                calc(minSum[l][k], minSum[k+1][r], l, r, l==k);
                calc(minSum[l][k], maxSum[k+1][r], l, r, l==k);
                calc(maxSum[l][k], minSum[k+1][r], l, r, l==k);
                calc(maxSum[l][k], maxSum[k+1][r], l, r, l==k);
            }
        }
        
        return maxSum[0][sz-1];
    }
    
    private void calc(int a, int b, int l, int r, boolean isLeftOne) {
        if (isLeftOne && a < 0) { // 가장 앞이 하나의 수만을 포함하며, 음수인 경우
            minSum[l][r] = Math.min(minSum[l][r], Math.min(a+b, a-b));
            maxSum[l][r] = Math.max(maxSum[l][r], Math.max(a+b, a-b));
        } else {
            minSum[l][r] = Math.min(minSum[l][r], a+b);
            maxSum[l][r] = Math.max(maxSum[l][r], a+b);
        }
    }
}