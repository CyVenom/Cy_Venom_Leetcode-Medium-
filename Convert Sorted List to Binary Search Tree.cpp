class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr; 

        if (!head->next) return new TreeNode(head->val); 

        ListNode* midPrev = findMiddlePrev(head);
        ListNode* mid = midPrev->next; 

        midPrev->next = nullptr; 

        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head); 
        root->right = sortedListToBST(mid->next); 

        return root;
    }

private:
    ListNode* findMiddlePrev(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return prev;
    }
};
