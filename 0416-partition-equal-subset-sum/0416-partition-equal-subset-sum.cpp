class Solution {
public:
    
//     bool solve(int ind,int k,vector<int>&nums,vector<vector<int>>&dp){
        
//         if(k==0)return true;
//         if(ind==0)return nums[0]==k;
        
//         if(dp[ind][k]!=-1)return dp[ind][k];
        
//         bool nottake=solve(ind-1,k,nums,dp);
//         bool take=false;
//         if(nums[ind]<=k)take=solve(ind-1,k-nums[ind],nums,dp);
        
//         return dp[ind][k]=take||nottake;
        
//     }
    
    
    
    bool canPartition(vector<int>& nums) {
        
        int sum=0,n=nums.size();
        if(n==1)return false;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum%2!=0)return false;
        int k=sum/2;
        // vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        // return solve(n-1,sum/2,nums,dp);
        // vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
            vector<bool>curr(sum+1,0),prev(sum+1,0);
            curr[0]=prev[0]=true;
            prev[nums[0]]=true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                int nottake=prev[j];
                int take=false;
                if(nums[i]<=j)take=prev[j-nums[i]];
                curr[j]=take||nottake;
            }
            prev=curr;
        }

            return prev[k];    
    }
};