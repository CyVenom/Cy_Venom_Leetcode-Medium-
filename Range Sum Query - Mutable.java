class NumArray {

    private int[] tree;
    private int[] nums;
    private int n;

    public NumArray(int[] nums) {
        this.nums = nums;
        this.n = nums.length;
        tree = new int[n + 1];
        for (int i = 0; i < n; i++) {
            add(i + 1, nums[i]);
        }
    }

    private void add(int index, int val) {
        while (index <= n) {
            tree[index] += val;
            index += index & -index;
        }
    }

    private int prefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    public void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        add(index + 1, diff);
    }

    public int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
}
