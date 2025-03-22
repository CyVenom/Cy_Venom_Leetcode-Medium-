#Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& temp, vector<vector<int>>& result) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
           
            if (used[i]) continue;

           
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, used, temp, result);
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> temp;
        
        
        sort(nums.begin(), nums.end());
        
        backtrack(nums, used, temp, result);
        return result;
    }
};
