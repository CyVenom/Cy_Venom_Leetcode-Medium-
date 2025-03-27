class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap; 
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1; 
        return build(postorder, inorder, inMap, postIndex, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, unordered_map<int, int>& inMap, int& postIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr; 

      
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        
        int inIndex = inMap[rootVal];

        
        root->right = build(postorder, inorder, inMap, postIndex, inIndex + 1, inEnd);
        root->left = build(postorder, inorder, inMap, postIndex, inStart, inIndex - 1);

        return root;
    }
};
