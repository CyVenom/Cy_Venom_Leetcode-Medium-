#You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

#A uni-value grid is a grid where all the elements of it are equal.

#Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

from typing import List

class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
     
        nums = [num for row in grid for num in row]
        
        
        remainder = [num % x for num in nums]
        if len(set(remainder)) > 1:
            return -1  
        
        
        nums.sort()
        median = nums[len(nums) // 2]
        
       
        return sum(abs(num - median) // x for num in nums)
