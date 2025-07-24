class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
          int count=0;
            
         sort(intervals.begin(),intervals.end());

        if(intervals.size()==1)return 0;
        int start=intervals[0][0];
        int end=intervals[0][1];
        int i=1;
        
        while(i<intervals.size())
         {
                if(end>intervals[i][0]){
                    end=min(end,intervals[i][1]);
                    count++;
                    i++;
                }
                else{
                    end=intervals[i][1];
                    i++;
                }
        }
        return count;
    }
};