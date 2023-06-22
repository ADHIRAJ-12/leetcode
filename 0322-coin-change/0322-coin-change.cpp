const int N=2510;
int dp[10010];

class Solution {
public:

    int f(int amount,vector<int>&coins){
        int ans=INT_MAX;
            if(amount==0)return 0;

        if(dp[amount]!=-1)return dp[amount];
        for(auto coin:coins){
            if(amount-coin>=0)
            ans=min(ans+0LL,1LL+f(amount-coin,coins));
        }
            return dp[amount]=ans;
    }


    int coinChange(vector<int>& coins, int amount) {
        
          // return solveTab(coins,amount);
          memset(dp,-1,sizeof(dp));
    int ans=f(amount,coins);
    return ans==INT_MAX? -1:ans;

    }
};
//     int solveTab(vector<int> &num,int x){
       
//         vector<int> dp(x+1,INT_MAX);
//         dp[0]=0;

//         for(int i=1;i<=x;i++){
//              for(int j=0;j<num.size();j++) {
//                  if(i-num[j] >=0 && dp[i-num[j]]!=INT_MAX){
//                      dp[i]=min(dp[i], 1+dp[i-num[j]]);
//                  }
//              } 
//         }

//          if (dp[x]==INT_MAX){
//                  return -1;}

//           return dp[x];
// }