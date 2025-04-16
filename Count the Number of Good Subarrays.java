class Solution {
    public long countGood(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> freq = new HashMap<>();
        long ans = 0;
        int left = 0;
        long pairs = 0;

        for (int right = 0; right < n; right++) {
            int val = nums[right];
            int count = freq.getOrDefault(val, 0);
            pairs += count;
            freq.put(val, count + 1);

            while (pairs >= k) {
                ans += n - right;
                int leftVal = nums[left];
                int leftCount = freq.get(leftVal);
                freq.put(leftVal, leftCount - 1);
                pairs -= leftCount - 1;
                left++;
            }
        }

        return ans;
    }
}
