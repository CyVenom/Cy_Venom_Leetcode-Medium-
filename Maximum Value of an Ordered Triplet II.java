class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long maxVal = 0;
        int maxPrefix = nums[0];
        int maxDiff = Integer.MIN_VALUE;
        
        for (int j = 1; j < n - 1; j++) {
            maxDiff = Math.max(maxDiff, maxPrefix - nums[j]);
            maxPrefix = Math.max(maxPrefix, nums[j]);
            maxVal = Math.max(maxVal, (long) maxDiff * nums[j + 1]);
        }
        
        return maxVal;
    }
}
