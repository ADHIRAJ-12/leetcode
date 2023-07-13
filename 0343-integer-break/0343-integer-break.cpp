class Solution {
public:
    int integerBreak(int n) {
        
        vector<int>dp(59);
        dp[1]=1;dp[2]=1;dp[3]=2;
        for(int i=4;i<=n;i++){
            int curr=i;
              for(int j=1;j<=curr;j++){
                  int prev=j;
                  int diff=curr-prev;
                  dp[i]=max({dp[i], dp[prev]*dp[diff],dp[prev]*diff,prev*dp[diff],prev*diff });
              }
        }
        
        return dp[n];
    }
};