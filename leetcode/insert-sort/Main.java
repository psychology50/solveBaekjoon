// @author 21911407 양재서

class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode answer = new ListNode();
        ListNode nxt, cur;

        while (head != null) {
            nxt = head.next;
            cur = answer;

            while (cur.next != null && cur.next.val <= head.val)
                cur = cur.next;

            head.next = cur.next;
            cur.next = head;
            head = nxt;
        }

        return answer.next;
    }
}