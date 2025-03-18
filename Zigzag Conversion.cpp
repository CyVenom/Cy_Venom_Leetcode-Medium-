#The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

#P   A   H   N
#A P L S I I G
#Y   I   R
#And then read line by line: "PAHNAPLSIIGYIR"

#Write the code that will take a string and make this conversion given a number of rows:

#string convert(string s, int numRows);


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;
        
        vector<string> rows(min(numRows, int(s.size())));
        int row = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[row] += c;
            if (row == 0 || row == numRows - 1) goingDown = !goingDown;
            row += goingDown ? 1 : -1;
        }

        string result;
        for (string& r : rows) result += r;
        return result;
    }
};

