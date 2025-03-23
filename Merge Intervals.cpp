#Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return{};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

     
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= merged.back()[1]) { 
                merged.back()[1] = max(merged.back()[1], intervals[i][1]); 
            } else {
                merged.push_back(intervals[i]); 
            }
        }

        return merged;
    }
};

