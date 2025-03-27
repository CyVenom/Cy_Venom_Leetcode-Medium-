class Solution {
public:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};
