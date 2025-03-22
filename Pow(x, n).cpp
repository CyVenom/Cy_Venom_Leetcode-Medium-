#Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

class Solution {
public:
    double myPow(double x, int n) {
        if ( n == 0) return 1;

        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if ( N % 2 == 1) result *= x;
            x *= x;
            N /= 2;

        }

        return result;
    }
};
