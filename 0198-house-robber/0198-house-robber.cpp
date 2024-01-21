class Solution {
public:

//     int solveTab(vector<int> &nums){
//         int n=nums.size();
//         int prev2=0;
//         int prev1=nums[0];

//         for(int i=1;i<n;i++){
//             int incl=prev2+nums[i];
//             int excl=prev1+0;
//             int ans=max(incl,excl);

//         prev2=prev1;
//         prev1=ans;
//     }
//     return prev1;
// }
    
    
    
    // int solve(int ind,vector<int> &dp,vector<int> &nums){
        
        
    //     if(ind ==0)return nums[ind];
    //     if(ind<0)return 0;
        
    //     if(dp[ind]!=-1)return dp[ind];
        
    //     int take=nums[ind]+solve(ind-2,dp,nums);        
    //     int notTake=0+solve(ind-1,dp,nums);
        
    //     return dp[ind]=max(take,notTake);
        
    // }
    
    
    int solve(int ind,vector<int>& dp,vector<int> & nums){
     
     if(ind==0)return nums[ind];
     if(ind<0)return 0;
     
     if(dp[ind]!=-1)return dp[ind];
    
    int take=nums[ind]+solve(ind-2,dp,nums);
    int nottake=0+solve(ind-1,dp,nums);

    return dp[ind]=max(take,nottake);

    }
    
    int rob(vector<int>& nums) {
        
        // return solveTab(nums);
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,dp,nums);

    }
};