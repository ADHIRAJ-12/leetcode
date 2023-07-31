class Solution {
public:

    int solve(int i, int j, string& s1, string& s2,vector<vector<int>>&dp){
       
        if(i==s1.size() && j == s2.size())return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int ans = INT_MAX;
        if(i == s1.size())ans = min(ans,s2[j] + solve(i,j+1,s1,s2,dp));
        
        else if(j == s2.size())ans = min(ans,s1[i] + solve(i+1,j,s1,s2,dp));
        
        else if(s1[i] == s2[j])ans = min(ans,solve(i + 1, j + 1, s1, s2,dp));
        
        else{
            ans = min(ans,s1[i] + solve(i + 1, j, s1, s2,dp));
            ans = min(ans,s2[j] + solve(i, j + 1, s1, s2,dp));
        }
        return dp[i][j] = ans;
        
        
    }
    
    
    
    int minimumDeleteSum(string s1, string s2) {
        
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,dp);
        
    }
};