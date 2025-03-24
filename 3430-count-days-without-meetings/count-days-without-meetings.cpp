class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); 
        
        int freeDays = days;  
        int end = 0;  

        for (auto& meeting : meetings) {
            int start = meeting[0], meetingEnd = meeting[1];

            if (start > end + 1) {  
              
                freeDays -= (meetingEnd - start + 1);
            } else {  
              
                freeDays -= max(0, meetingEnd - end);
            }

            end = max(end, meetingEnd);
        }

        return freeDays;
    }
};
