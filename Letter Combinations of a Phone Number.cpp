#Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
#A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 

        
        vector<string> digitToLetters = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;
        backtrack(0, digits, digitToLetters, current, result);
        return result;
    }

private:
    void backtrack(int index, const string& digits, const vector<string>& digitToLetters, string& current, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current); 
            return;
        }

        string letters = digitToLetters[digits[index] - '0']; 
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(index + 1, digits, digitToLetters, current, result);
            current.pop_back(); 
        }
    }
};
