class Solution {
public:

    int possible(int mid,vector<int>& nums){
        int count=1,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid)sum+=nums[i];
            else{
                count++;
                sum=nums[i];
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        
        if(k>nums.size())return -1;
        int maxi=INT_MIN,sum=0;
        
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        int s=maxi,e=sum;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(mid,nums)>k)s=mid+1;
            else e=mid-1;
        }
        return s;

    }
};