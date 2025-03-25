#Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
#You may return the answer in any order.

class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        backtrack(1, n, k, current);
        return result;
    }

private:
    void backtrack(int start, int n, int k, vector<int>& current) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++) {
            current.push_back(i);
            backtrack(i + 1, n, k, current);
            current.pop_back();  // Backtrack
        }
    }
};
