class Solution {
public:
    
vector<char>v={'a','e','i','o','u'};

    int f(int c,int vow,int n, vector<vector<int>>&dp ){
        
        if(vow>=5)return 0;
        if(c>=n)return 1;
        
        if(dp[c][vow]!=-1)return dp[c][vow];
        
        int a=f(c+1,vow,n,dp);
        int b=f(c,vow+1,n,dp);
        
        return dp[c][vow]=a+b;

        
        
    }
    
    
    int countVowelStrings(int n) {
        
        vector<vector<int>>dp(n,vector<int>(5,-1));
        return f(0,0,n,dp);
    }
};