#Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);  
        dummy->next = head;
        ListNode* prev = dummy;  

        while (head) {
            bool isDuplicate = false;
            while (head->next && head->val == head->next->val) {
                head = head->next; 
                isDuplicate = true;
            }

            if (isDuplicate) {
                prev->next = head->next; 
            } else {
                prev = prev->next; 
            }

            head = head->next; 
        }

        return dummy->next;
    }
};
