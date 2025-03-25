#You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

# (startx, starty): The bottom-left corner of the rectangle.
# (endx, endy): The top-right corner of the rectangle.
#Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

#Each of the three resulting sections formed by the cuts contains at least one rectangle.
#Every rectangle belongs to exactly one section.
#Return true if such cuts can be made; otherwise, return false.

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return checkCuts(rectangles, true) || checkCuts(rectangles, false);
    }

private:
    bool checkCuts(vector<vector<int>>& rectangles, bool vertical) {
        set<int> cutPositions;
        unordered_map<int, int> leftCount, rightCount;
        
        
        for (const auto& rect : rectangles) {
            int start = vertical ? rect[0] : rect[1];
            int end = vertical ? rect[2] : rect[3];
            cutPositions.insert(start);
            cutPositions.insert(end);
            leftCount[start]++;
            rightCount[end]++;
        }

        vector<int> cuts(cutPositions.begin(), cutPositions.end());
        int totalRectangles = rectangles.size();
        int leftSum = 0, rightSum = totalRectangles;

        
        for (int i = 0; i < cuts.size(); i++) {
            leftSum += leftCount[cuts[i]];
            rightSum -= rightCount[cuts[i]];

            for (int j = i + 1; j < cuts.size(); j++) {
                int middleSum = totalRectangles - leftSum - rightSum;
                if (leftSum > 0 && middleSum > 0 && rightSum > 0) {
                    return true;
                }
                leftSum += leftCount[cuts[j]];
                rightSum -= rightCount[cuts[j]];
            }

            leftSum = 0;
            rightSum = totalRectangles;
        }
        
        return false;
    }
};
