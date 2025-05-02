class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         vector<pair<int,int>>temp;
         stack<double>s;

        for(int i=0;i<position.size();i++)
        {
            temp.push_back({position[i],speed[i]});

        }
           sort(temp.rbegin(), temp.rend());

        for(auto ch:temp)
        {
            double time_taken=  (double)(target - ch.first) / ch.second;

            if(s.empty())
            {
                s.push(time_taken);
            }
            else{
                if(time_taken>s.top())
                {
                    s.push(time_taken);
                }
            }
        }

          return s.size();
    }
};