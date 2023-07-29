class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,c=0,ans=0;
        for(r=0;r<n;r++){
            if(nums[r]==0)c++;
            if(c>1 && nums[l++]==0)c--;
            ans=max(ans,r-l);
        }
        return ans;
        
    }
};