class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head; 

        ListNode dummy(0); 
        dummy.next = head;
        ListNode* prev = &dummy;

        
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        
        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        ListNode* prevRev = nullptr;

        for (int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = prevRev;
            prevRev = curr;
            curr = next;
        }

        
        prev->next->next = curr; 
        prev->next = prevRev;    

        return dummy.next;
    }
};
