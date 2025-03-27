#Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
#You should preserve the original relative order of the nodes in each of the two partitions.

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0), greaterDummy(0); 
        ListNode *lessTail = &lessDummy, *greaterTail = &greaterDummy;

        
        while (head) {
            if (head->val < x) {
                lessTail->next = head;
                lessTail = lessTail->next;
            } else {
                greaterTail->next = head;
                greaterTail = greaterTail->next;
            }
            head = head->next;
        }

       
        lessTail->next = greaterDummy.next;
        greaterTail->next = nullptr; 

        return lessDummy.next;
    }
};
