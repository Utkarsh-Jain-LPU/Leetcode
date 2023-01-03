/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode result = null;
        ListNode root = null;
        while (list1 != null && list2 != null) {
            if (list2.val <= list1.val) {
                if (result == null) {
                    result = new ListNode(list2.val);
                    root = result;
                    list2 = list2.next;
                } else {
                    ListNode node = new ListNode(list2.val);
                    result.next = node;
                    result = result.next;
                    list2 = list2.next;
                }
            } else {
                if (result == null) {
                    result = new ListNode(list1.val);
                    root = result;
                    list1 = list1.next;
                } else {
                    ListNode node = new ListNode(list1.val);
                    result.next = node;
                    result = result.next;
                    list1 = list1.next;
                }
            }
        }
        if (list1 == null && list2 != null) {
            if (result == null) {
                result = new ListNode(list2.val);
                result.next = list2.next;
                root = result;
            } else {
                result.next = list2;
            }
        }
        if (list2 == null && list1 != null) {
            if (result == null) {
                result = new ListNode(list1.val);
                result.next = list1.next;
                root = result;
            } else {
                result.next = list1;
            }
        }
        return root;
    }
}
