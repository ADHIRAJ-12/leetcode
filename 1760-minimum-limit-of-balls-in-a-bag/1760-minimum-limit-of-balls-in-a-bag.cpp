class Solution {
public:

    int minimumSize(vector<int>& nums, int k) {
        
        int n=nums.size(),maxi=INT_MIN;
        for(int i=0;i<n;i++)maxi=max(maxi,nums[i]);
        int s=1,e=maxi;
        int c=0;
        while(s<=e){
            int mid=s+(e-s)/2;
               c=0;
                for(auto &i: nums){
                if(i%mid)c += i/mid;
                else c += i/mid-1;
            }
            if(c>k)s = mid+1;
            else e= mid-1;
        }
        return s;
       
    }
};