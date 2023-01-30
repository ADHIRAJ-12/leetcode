class Solution {
public:
    
//     int solve(int n,vector<int>&dp){
        
//         if(n<=1)return n;
//         if(n==2)return 1;
        
//         if(dp[n]!=-1)return dp[n];
        
        
//          dp[n]=solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
        
        
//         return dp[n];
        
//     }
    
        int solve(int n){
        
          
       if(n==0) return 0;
       if(n==1) return 1;
       if(n==2) return 1;
            
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
            
            for(int i=3;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
            }

           return dp[n];
    }
    
    
    int tribonacci(int n) {
        // vector<int>dp(n+1,-1);
        // return solve(n,dp);
        return solve(n);

        
        
    }
};