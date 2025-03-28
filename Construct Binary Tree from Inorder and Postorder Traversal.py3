class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not inorder or not postorder:
            return None

        # The last element of postorder is the root
        root_val = postorder.pop()
        root = TreeNode(root_val)

        # Find the index of the root in inorder
        root_index = inorder.index(root_val)

        # Recursively build the right and left subtrees
        root.right = self.buildTree(inorder[root_index+1:], postorder)
        root.left = self.buildTree(inorder[:root_index], postorder)

        return root
