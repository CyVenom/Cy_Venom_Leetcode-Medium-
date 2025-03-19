#Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

#Return the sum of the three integers.

#You may assume that each input would have exactly one solution.


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // Sort the array
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with the first three numbers

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum; // Update closest sum if needed
                }

                if (sum < target) {
                    left++; // Increase sum
                } else if (sum > target) {
                    right--; // Decrease sum
                } else {
                    return sum; // If exact match found, return immediately
                }
            }
        }
        return closestSum;
    }
};
