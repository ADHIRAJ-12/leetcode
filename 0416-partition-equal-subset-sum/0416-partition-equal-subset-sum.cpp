class Solution {
public:
    
    bool solve(int ind,int k,vector<int>&nums,vector<vector<int>>&dp){
        
        if(k==0)return true;
        if(ind==0)return nums[0]==k;
        
        if(dp[ind][k]!=-1)return dp[ind][k];
        
        bool nottake=solve(ind-1,k,nums,dp);
        bool take=false;
        if(nums[ind]<=k)take=solve(ind-1,k-nums[ind],nums,dp);
        
        return dp[ind][k]=take||nottake;
        
    }
    
    
    
    bool canPartition(vector<int>& nums) {
        
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum%2!=0)return false;
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        return solve(n-1,sum/2,nums,dp);
        
    }
};