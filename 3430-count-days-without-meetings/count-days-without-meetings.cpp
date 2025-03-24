class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());  // Sort by start time
        
        int freeDays = days;  // Start with all days as free
        int end = 0;  // Track the last occupied day

        for (auto& meeting : meetings) {
            int start = meeting[0], meetingEnd = meeting[1];

            if (start > end + 1) {  
                // If there's a gap, count the free days
                freeDays -= (meetingEnd - start + 1);
            } else {  
                // Merge intervals
                freeDays -= max(0, meetingEnd - end);
            }

            end = max(end, meetingEnd);
        }

        return freeDays;
    }
};
