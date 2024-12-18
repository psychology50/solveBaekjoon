import java.util.*;

class Solution {
    Map<String, String> parent = new HashMap<>();
    Map<String, Integer> money = new HashMap<>();

    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        for (int i = 0; i < enroll.length; i++) {
            parent.put(enroll[i], referral[i]);
        }

        for (int i = 0; i < seller.length; i++) {
            share(seller[i], amount[i] * 100);
        }

        int[] result = new int[enroll.length];
        for (int i = 0; i < enroll.length; i++) {
            result[i] = money.getOrDefault(enroll[i], 0);
        }

        return result;
    }

    void share(String node, int sales) {
        int nextSales = sales / 10;
        money.put(node, money.getOrDefault(node, 0) + sales - nextSales);

        if (nextSales > 0 && parent.containsKey(node)) {
            share(parent.get(node), nextSales);
        }
    }
}