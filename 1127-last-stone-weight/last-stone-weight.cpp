class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)return stones[0];

      priority_queue<int>Q(stones.begin(),stones.end());

       while(Q.size()>1)
       {

         int first =Q.top();
         Q.pop();
         int second=Q.top();
         Q.pop();

          if(first==second) {
            continue;
          }
          else{
               
               int remaining =first-second;
               Q.push(remaining);

          }

       }
       return Q.size()==1?Q.top():0;
           
    }
};