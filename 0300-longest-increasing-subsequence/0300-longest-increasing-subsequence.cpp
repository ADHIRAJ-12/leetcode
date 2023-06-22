const int N=25e2+10;
int dp[N];

class Solution {
public:

    
    //NOW IMPORTANT CONCEPT OF N=BINARY SEARCH WITH DP
    
//     int solveBinary(int n,vector<int>& nums){
        
//         if(n==0) return 0;
        
//         vector<int>ans;
//         ans.push_back(nums[0]);
        
//         for(int i=1;i<n;i++){
//             if(nums[i]>ans.back()) ans.push_back(nums[i]);
            
//             else{
//                 //find index of just bda element
//                 int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
//                 ans[index]=nums[i];
//             }
//         }
//         return ans.size();
//     }
    
    
    int lis(int i,vector<int> &nums){
        int ans=1;
        if(dp[i]!=-1)return dp[i];
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                ans=max(ans,lis(j,nums)+1);
            }
        }
        return dp[i]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int  ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,lis(i,nums));
        }
        return ans;

    }
};
    

        
        
        
           // vector<vector<int>>dp(n,vector<int>(n+1,-1));
            // return solve(n,nums,0,-1); 

                    // return solveMem(n,nums,0,-1,dp); 

             // return solveTab(n,nums);
                     // return solveSpace(n,nums);



//     int solve(int n,vector<int>& nums,int curr ,int prev){
//         //base
//         if(curr==n) return 0;
        
//         //include  (include 1st element always, 1st element means prev=-1)
        
//         int include=0;
//         if(prev==-1 || nums[curr]>nums[prev])
//             include=1+solve(n,nums,curr+1,curr);
        
//         int exclude=0+solve(n,nums,curr+1,prev);
        
//         return max(include,exclude);
//     }
    
//     int solveMem(int n,vector<int>& nums,int curr ,int prev,vector<vector<int>> &dp){
//         //base
//         if(curr==n) return 0;
        
//         if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        
//         //include  (include 1st element always, 1st element means prev=-1)
        
//         int include=0;
//         if(prev==-1 || nums[curr]>nums[prev])
//             include=1+solveMem(n,nums,curr+1,curr,dp);
        
//         int exclude=0+solveMem(n,nums,curr+1,prev,dp);
        
//                                                          //+1 bcoz prev =-1 initially so handling that case
//         return dp[curr][prev] =max(include,exclude);
//     }
    
     
//     int solveTab(int n,vector<int>& nums){
       
//        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
//         for(int curr=n-1;curr>=0;curr--){
//             for(int prev=curr-1;prev>=-1;prev--){
                
                
//                  int include=0;
//         if(prev==-1 || nums[curr]>nums[prev])
//             include=1+dp[curr+1][curr+1];
        
//         int exclude=0+dp[curr+1][prev+1];
        
//         dp[curr][prev+1] =max(include,exclude);
                
                
                
                
//             }
//         }
        

//         return dp[0][0];
//     }
    
    
      
//     int solveSpace(int n,vector<int>& nums){
      
//       vector<int>currRow(n+1,0);
//       vector<int>nextRow(n+1,0);  

//         for(int curr=n-1;curr>=0;curr--){
//             for(int prev=curr-1;prev>=-1;prev--){
                
                
//                  int include=0;
//         if(prev==-1 || nums[curr]>nums[prev])
//             include=1+nextRow[curr+1];
        
//         int exclude=0+nextRow[prev+1];
        
//         currRow[prev+1] =max(include,exclude);
                
//             }
//             nextRow=currRow;
//         }
        

//         return nextRow[0];
//     }
    
    
    
    
    
    
    
    
    
    
    