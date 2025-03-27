class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0; // No valid decoding for empty or leading '0'
        
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: empty string
        dp[1] = (s[0] != '0') ? 1 : 0; // Single character check

        for (int i = 2; i <= n; i++) {
            // Check single digit (1-9)
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            // Check two-digit (10-26)
            int twoDigit = stoi(s.substr(i - 2, 2)); // Extract two-digit number
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
