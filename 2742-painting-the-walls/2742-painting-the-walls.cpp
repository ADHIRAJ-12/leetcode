class Solution {
public:
    
    int solve(vector<int>& cost,vector<int>& time,int ind,int n, vector<vector<int>> &dp){
         if(n<= 0) return 0;
        if(ind >= cost.size()) return 1000000000;
        if(dp[ind][n]!=0)return dp[ind][n];
        
        int take=cost[ind]+solve(cost,time,ind+1,n-1-time[ind],dp);
        int notTake=solve(cost,time,ind+1,n,dp);
        
        return dp[ind][n] = min(notTake, take); 
        
    }
    
    
  int paintWalls(vector<int>& cost, vector<int>& time) {
      int n=cost.size();
      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      return solve(cost,time,0,time.size(),dp);
    
    }
};
