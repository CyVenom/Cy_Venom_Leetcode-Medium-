class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string currentIP;
        backtrack(s, 0, 0, currentIP, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, int partCount, string currentIP, vector<string>& result) {
        if (partCount == 4 && start == s.size()) {
            result.push_back(currentIP);
            return;
        }
        if (partCount == 4 || start == s.size()) return;

        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.size()) break;

            string segment = s.substr(start, len);
            if (!isValid(segment)) continue;

            string newIP = currentIP.empty() ? segment : currentIP + "." + segment;
            backtrack(s, start + len, partCount + 1, newIP, result);
        }
    }

    bool isValid(const string& segment) {
        if (segment.size() > 1 && segment[0] == '0') return false; 
        int num = stoi(segment);
        return num >= 0 && num <= 255;
    }
};
