class Solution {
    public int findNthDigit(int n) {
        if (n <= 9) {
            return n;
        }
        
        long x = 9;
        int d = 1;
        int num = 0;
        int p = n;
        
        while (p > (x * d)) {
            p -= x * d;
            num += x;
            x *= 10;
            d++;
        }
        
        num += p / d;
        p %= d;
        
        if (p == 0) {
            return num % 10;
        } else {
            num++;
            x = (int) Math.pow(10, d - p);
            num /= x;
            return num % 10;
        }
    }
}
