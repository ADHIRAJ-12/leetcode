class Solution {
public:
    
//     bool solve(int index,vector<int>& nums,int N,int target){
        
//          if(index>=N || target<0) return false;
//         if(target==0) return true;
        
//         int include=solve(index+1,nums,N,target-nums[index]);
//         int exclude=solve(index+1,nums,N,target-0);
        
//         return include or exclude;
        
//     }
    
    
//       bool solveMem(int index,vector<int>& nums,int N,int target,vector<vector<int>> &dp){
        
//          if(index>=N || target<0) return false;
//         if(target==0) return true;
//           if(dp[index][target]!=-1) return dp[index][target];
        
//         int include=solveMem(index+1,nums,N,target-nums[index],dp);
//         int exclude=solveMem(index+1,nums,N,target-0,dp);
        
//         return dp[index][target]= include or exclude;
        
//     }
    
    
//     bool solveTab(int N,vector<int>& nums,int total){
    
//         vector<vector<int>>dp(N+1,vector<int>(total+1,0));

//         for(int i=0;i<=N;i++){
//             dp[i][0]=1;
            
//         }      
//         for(int index=N-1;index>=0;index--){
//             for(int target=0;target<=total/2;target++){
                
//                 bool include=0;
//                 if(target-nums[index]>=0)
//                  include=dp[index+1][target-nums[index]];
            
//                 bool exclude=dp[index+1][target];

//                 dp[index][target]= include or exclude;
//             }
//         }
//         return dp[0][total/2];
//     }
    
    
    
    
      bool solveSpace(int N,vector<int>& nums,int total){
    
        vector<int>curr(total+1,0);       
         vector<int>next(total+1,0);

          curr[0]=1;
          next[0]=1;
     
        for(int index=N-1;index>=0;index--){
            for(int target=0;target<=total/2;target++){
                
                bool include=0;
                if(target-nums[index]>=0)
                 include=next[target-nums[index]];
            
                bool exclude=next[target];

                curr[target]= include or exclude;
            }
            next=curr;
        }
        return next[total/2];
    }
    
    
    
    
    
    
    bool canPartition(vector<int>& nums) {
        int N=nums.size();
        int total=0;
        
        for(int i=0;i<N;i++){
            total+=nums[i];
        }
        if(total&1) return 0;  //means odd
        
        int target=total/2;
        // return solve(0,nums,N,target);
        // vector<vector<int>>dp(N,vector<int>(target+1,-1));
        // return solveMem(0,nums,N,target,dp);
        
        // return solveTab(N,nums,total);
                return solveSpace(N,nums,total);

    }
};