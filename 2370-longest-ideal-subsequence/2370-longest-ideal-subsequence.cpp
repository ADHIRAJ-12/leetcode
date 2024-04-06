class Solution {
public:
       
    int solve(int ind,int prev,string &arr,int n,vector<vector<int>>&dp,int k){

             if(ind>=n)return 0;

             if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];

             int nottake=solve(ind+1,prev,arr,n,dp,k);
             int take=0;
            if( prev==-1 || abs(arr[ind]-prev)<=k)  take=1+solve(ind+1,arr[ind],arr,n,dp,k);

             return dp[ind][prev+1]=  max(take,nottake);

 }
    
    
    int longestIdealString(string s, int k) {
        
          int n=s.size();
         vector<vector<int>>dp(n+1,vector<int>(150,-1));
         return solve(0,-1,s,n,dp,k);   
        
        
    }
};