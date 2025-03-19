class Solution {
public:
  
   bool check(int start, int n, vector<int>& nums) {
       if (start + 2 >= n) {  // Ensure valid range
           return false;
       }

       for (int i = start; i < start + 3; i++) {  
           nums[i] ^= 1;  // Flip 0 to 1 and 1 to 0
       }

       return true;
   }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (!check(i, n, nums)) return -1;
                count++;
            }
        }

        return count;
    }
};
