#Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
#The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
#The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {  
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) continue; 

            current.push_back(candidates[i]); 
            backtrack(candidates, target - candidates[i], i, current, result); 
            current.pop_back(); 
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};
