class Solution {
public:
    int solve(int ind,int prev,vector<int>&arr,int n,vector<vector<int>>&dp){

     if(ind==n)return 0;
     
     if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];

     int nottake=solve(ind+1,prev,arr,n,dp);
     int take=0;
     if(prev==-1||arr[ind]>arr[prev])take=1+solve(ind+1,ind,arr,n,dp);

     return dp[ind][prev+1]=  max(take,nottake);

 }


    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
         vector<vector<int>>dp(n,vector<int>(n+1,-1));
         return solve(0,-1,nums,n,dp);   
    }
};