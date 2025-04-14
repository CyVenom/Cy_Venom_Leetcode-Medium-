class Solution {
    public int superPow(int a, int[] b) {
        final int MOD = 1337;
        a = a % MOD;  // Reduce a mod 1337 first to avoid overflow
        
        int res = 1;
        for (int i = 0; i < b.length; i++) {
            res = modExp(res, 10, MOD);  // Update the result to account for powers of 10
            res = (res * modExp(a, b[i], MOD)) % MOD;  // Multiply with a^b[i] % MOD
        }
        
        return res;
    }
    
    // Function to compute a^k % mod
    public int modExp(int a, int k, int mod) {
        int result = 1;
        a = a % mod;  // Make sure a is within mod range
        while (k > 0) {
            if (k % 2 == 1) {
                result = (result * a) % mod;  // Multiply when exponent is odd
            }
            a = (a * a) % mod;  // Square the base
            k /= 2;  // Divide the exponent by 2
        }
        return result;
    }
}
