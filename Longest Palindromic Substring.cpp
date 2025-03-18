# Given a string s, return the longest palindromic substring in s.

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;
        
        // Function to expand around the center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Update max palindrome substring
            if (right - left - 1 > maxLen) {
                start = left + 1;
                maxLen = right - left - 1;
            }
        };

        for (int i = 0; i < s.size(); i++) {
            expandAroundCenter(i, i);     // Odd-length palindrome
            expandAroundCenter(i, i + 1); // Even-length palindrome
        }
        
        return s.substr(start, maxLen);
    }
};


