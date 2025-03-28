class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.prev = None  
        
        def reversePreorder(node):
            if not node:
                return
            
           
            reversePreorder(node.right)
            reversePreorder(node.left)
            
            
            node.right = self.prev  
            node.left = None  
            self.prev = node  
        
        reversePreorder(root)
