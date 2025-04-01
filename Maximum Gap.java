class Solution {
    public int maximumGap(int[] nums) {
        if (nums.length < 2) return 0;
        
        int maxVal = Arrays.stream(nums).max().getAsInt();
        int minVal = Arrays.stream(nums).min().getAsInt();
        int n = nums.length;
        
        int bucketSize = Math.max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;
        
        int[] minBucket = new int[bucketCount];
        int[] maxBucket = new int[bucketCount];
        Arrays.fill(minBucket, Integer.MAX_VALUE);
        Arrays.fill(maxBucket, Integer.MIN_VALUE);
        
        for (int num : nums) {
            int idx = (num - minVal) / bucketSize;
            minBucket[idx] = Math.min(minBucket[idx], num);
            maxBucket[idx] = Math.max(maxBucket[idx], num);
        }
        
        int maxGap = 0, prevMax = minVal;
        
        for (int i = 0; i < bucketCount; i++) {
            if (minBucket[i] == Integer.MAX_VALUE) continue;
            maxGap = Math.max(maxGap, minBucket[i] - prevMax);
            prevMax = maxBucket[i];
        }
        
        return maxGap;
    }
}
