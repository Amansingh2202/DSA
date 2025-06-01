class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low=0;
        int ans=-1;
        int high=arr.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
             if(arr[mid]==target)
             {
                ans=mid;
                break;
             }
             else if(arr[mid]>target)
             {
                high=mid-1;
             }
             else{
                low=mid+1;
             }

        }
        return ans;
     
    }
    

};