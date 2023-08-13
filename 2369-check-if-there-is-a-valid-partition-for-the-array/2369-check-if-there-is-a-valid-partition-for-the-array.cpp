class Solution {
public:
    
    bool solve(int ind,vector<int>&nums,vector<int>&dp){
            
        int n=nums.size();
        if(ind==n)return true;
        
        if(dp[ind]!=-1)return dp[ind];
        bool flag=false;
        if( ind+1<n && nums[ind]==nums[ind+1] ){
            flag=solve(ind+2,nums,dp);
            if(nums[ind+2]==nums[ind] && ind+2<n){
                flag=flag||solve(ind+3,nums,dp);
            }
        }
        
        if(ind+2<n && nums[ind+1]-nums[ind]==1 && nums[ind+2]-nums[ind+1]==1  ){
            flag=flag||solve(ind+3,nums,dp);
        }
        return dp[ind]=flag;
        
    }
    
    
    
    
    
    bool validPartition(vector<int>& nums) {
        int  n=nums.size();
        if(n==2)return (nums[0]==nums[1]);
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};