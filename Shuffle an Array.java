class Solution {
    private int[] original;
    private int[] nums;
    private Random rand;

    public Solution(int[] nums) {
        this.original = nums.clone();  // Store the original array
        this.nums = nums;
        this.rand = new Random();
    }

    // Reset the array to its original configuration
    public int[] reset() {
        nums = original.clone();
        return nums;
    }

    // Shuffle the array randomly
    public int[] shuffle() {
        // Fisher-Yates shuffle algorithm
        for (int i = nums.length - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1);  // Random index from 0 to i
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        return nums;
    }
}
