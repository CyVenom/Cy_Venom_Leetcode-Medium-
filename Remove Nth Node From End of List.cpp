#Given the head of a linked list, remove the nth node from the end of the list and return its head.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head); 
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        
        while (first) {
            first = first->next;
            second = second->next;
        }

       
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete; 

        return dummy->next;
    }
};
