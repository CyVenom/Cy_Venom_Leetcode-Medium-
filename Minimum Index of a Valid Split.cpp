#An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

#You are given a 0-indexed integer array nums of length n with one dominant element.

#You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

#0 <= i < n - 1
#nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
#Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

#Return the minimum index of a valid split. If no valid split exists, return -1.

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        
        int candidate = -1, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

       
        int totalCount = 0;
        for (int num : nums) {
            if (num == candidate) totalCount++;
        }

        
        int leftCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == candidate) {
                leftCount++;
            }
            int rightCount = totalCount - leftCount;

            
            if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                return i;
            }
        }
        
        return -1; 
    }
};
