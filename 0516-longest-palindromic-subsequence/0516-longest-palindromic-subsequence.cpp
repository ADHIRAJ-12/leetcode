class Solution {
public:
    
    int solve(string &s,string &rev,int i,int j,vector<vector<int>> &dp){
        
        if(i==s.size()||j==rev.size())return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s[i]==rev[j])ans=1+solve(s,rev,i+1,j+1,dp);
        else ans=max(solve(s,rev,i,j+1,dp),solve(s,rev,i+1,j,dp));
        return dp[i][j]=ans;
    }
      
    
    int longestPalindromeSubseq(string s) {
    
        string rev=s;
        reverse(rev.begin(),rev.end());
        int n=s.size(),m=rev.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,rev,0,0,dp);
    
    }
};








// class Solution {
// public:
    
//       int solve(string &a, string &b,int i,int j,vector<vector<int>> &dp){
        
//         if(i==a.length() ||j==b.length())return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
//         int ans=0;
//         if(a[i]==b[j]) ans=1+solve(a,b,i+1,j+1,dp);
        
//         else ans= max(solve(a,b,i,j+1,dp),solve(a,b,i+1,j,dp));
        
//         return dp[i][j]= ans;
//     }
    
//     int longestPalindromeSubseq(string s) {
//          string rev=s;
//          reverse(rev.begin(),rev.end());
//          int n1=s.size();
//          int n2=rev.size();

//         vector<vector<int>>dp(n1,vector<int>(n2,-1));
//         return solve(s,rev,0,0,dp); 
//     }
// };