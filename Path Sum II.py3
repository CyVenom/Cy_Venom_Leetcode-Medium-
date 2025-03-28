class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        result = []

        def dfs(node, path, currSum):
            if not node:
                return
            
            path.append(node.val)  
            currSum += node.val  
            
            if not node.left and not node.right and currSum == targetSum:
                result.append(list(path))  
            
            dfs(node.left, path, currSum)
            dfs(node.right, path, currSum)

            path.pop()  
        dfs(root, [], 0)
        return result
