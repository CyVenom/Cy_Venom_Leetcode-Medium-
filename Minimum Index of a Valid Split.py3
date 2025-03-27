#An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

#You are given a 0-indexed integer array nums of length n with one dominant element.

#You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

#0 <= i < n - 1
#nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
#Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

#Return the minimum index of a valid split. If no valid split exists, return -1.

class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        
        candidate, count = None, 0
        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)
        
       
        total_count = nums.count(candidate)
        
       
        left_count = 0 
        for i in range(len(nums) - 1):
            if nums[i] == candidate:
                left_count += 1
            right_count = total_count - left_count  
            
            
            if left_count * 2 > (i + 1) and right_count * 2 > (len(nums) - i - 1):
                return i
        
        return -1
