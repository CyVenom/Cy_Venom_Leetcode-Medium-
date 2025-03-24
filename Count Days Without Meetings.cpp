#You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
#Return the count of days when the employee is available for work but no meetings are scheduled.
#Note: The meetings may overlap.

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

     
        sort(meetings.begin(), meetings.end());

        int busyDays = 0, lastEnd = 0;

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            
            if (start > lastEnd + 1) {
                busyDays += (end - start + 1);
            } else {
                
                busyDays += max(0, end - lastEnd);
            }

            lastEnd = max(lastEnd, end);
        }

        return days - busyDays;
    }
};
