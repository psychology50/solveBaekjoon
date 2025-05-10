import java.math.BigInteger;
import java.util.*;

class Solution {
    public int solution(int[] arr) {
        int[] tmp = arr.clone();

        for (int i=0; i<arr.length-1; i++) {
            BigInteger b1 = BigInteger.valueOf(tmp[i]);
            BigInteger b2 = BigInteger.valueOf(tmp[i+1]);
                
            BigInteger gcd = b1.gcd(b2);
            
            tmp[i+1] = (tmp[i] * tmp[i+1]) / gcd.intValue();
        }
        return tmp[tmp.length-1];
    }
}