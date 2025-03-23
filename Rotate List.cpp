#Given the head of a linked list, rotate the list to the right by k places.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; 

        
        ListNode* temp = head;
        int n = 1;
        while (temp->next) {
            temp = temp->next;
            n++;
        }

 
        k = k % n;
        if (k == 0) return head; 

        
        temp->next = head;

        
        ListNode* newTail = head;
        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;

        
        newTail->next = NULL;

        return newHead;
    }
};
