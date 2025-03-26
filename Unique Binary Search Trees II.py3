#Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        if n == 0:
            return []
        
        def build_trees(start, end):
            if start > end:
                return [None]  
            
            all_trees = []
            for root_val in range(start, end + 1):
                left_subtrees = build_trees(start, root_val - 1)  
                right_subtrees = build_trees(root_val + 1, end)   

                
                for left in left_subtrees:
                    for right in right_subtrees:
                        root = TreeNode(root_val, left, right)
                        all_trees.append(root)
            
            return all_trees
        
        return build_trees(1, n)


 
