#Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

#You have the following three operations permitted on a word:

#Insert a character
#Delete a character
#Replace a character

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;

       
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; 
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
        }

        return dp[m][n];
    }
};



#Solution 2
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        
        for (int j = 0; j <= n; j++) prev[j] = j; 
        
        for (int i = 1; i <= m; i++) {
            curr[0] = i; 
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = min({prev[j], curr[j - 1], prev[j - 1]}) + 1;
                }
            }
            prev = curr; 
        }

        return prev[n];
    }
};


