class Solution {
public:
    

// int solve(int i,int j,string s, string t,vector<vector<int>>&dp){

//     //if one of the string ends reuturn 0 as there will be nothing common
//     if(i<0||j<0)return 0;

//     if(dp[i][j]!=-1)return dp[i][j];

//     //if current index elements are same add 1 to result and check further
//     if(s[i]==t[j])return  dp[i][j]=1+solve(i-1,j-1,s,t,dp);

//     //if current index elements are diff,check by moving each pointer one by one,return whichever gives the lcs

//     return  dp[i][j]= max(solve(i,j-1,s,t,dp), solve(i-1,j,s,t,dp));
// }

    
    
    
    int longestCommonSubsequence(string s, string t) {
        
        int n=s.size(),m=t.size();
        // vector<vector<int>>dp(n,vector<int>(m+1,-1));
        // return solve(n-1,m-1,s,t,dp);
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

            for(int i=0;i<=n;i++)dp[i][0]=0;
            for(int j=0;j<=m;j++)dp[0][j]=0;

            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
                }
            }

            return  dp[n][m];
        
    }
};