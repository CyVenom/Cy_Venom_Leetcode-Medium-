#Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

#The solution set must not contain duplicate subsets. Return the solution in any order.


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()  
        
        def backtrack(start, path):
            res.append(path[:])  
            for i in range(start, len(nums)):
                if i > start and nums[i] == nums[i - 1]: 
                    continue
                path.append(nums[i])  
                backtrack(i + 1, path) 
                path.pop()  
        
        backtrack(0, [])
        return res

