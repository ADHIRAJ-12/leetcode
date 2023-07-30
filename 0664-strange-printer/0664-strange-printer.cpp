class Solution {
public:
    int strangePrinter(string s) {
     
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,1));
        
        for(int i=n-1;i>=0;i--){
            for(int d=1;d<n-i;d++){
                int j=d+i;
                    if(d==1){
                        dp[i][j]=(s[i]==s[j]?1:2);
                        continue;
                    }
                dp[i][j]=1001;
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
                if(s[i]==s[j])dp[i][j]-=1;
            }
        }
        return dp[0][n-1];
        
        
    }
};  