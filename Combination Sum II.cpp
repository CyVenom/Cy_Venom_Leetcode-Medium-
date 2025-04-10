#Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
#Each number in candidates may only be used once in the combination.
#Note: The solution set must not contain duplicate combinations.

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) { 
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue; 

            if (candidates[i] > target) break; 

            current.push_back(candidates[i]); 
            backtrack(candidates, target - candidates[i], i + 1, current, result); 
            current.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end()); 
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};
