#You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

#A uni-value grid is a grid where all the elements of it are equal.

#Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        int m = grid.size(), n = grid[0].size();

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                values.push_back(grid[i][j]);
            }
        }

       
        int mod_base = values[0] % x;
        for (int num : values) {
            if (num % x != mod_base) return -1;
        }

        
        sort(values.begin(), values.end());
        int median = values[values.size() / 2];

        int operations = 0;
        for (int num : values) {
            operations += abs(num - median) / x;
        }

        return operations;
    }
};
