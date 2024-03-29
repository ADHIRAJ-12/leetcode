class Solution {
public:

    
    int longestCommonSubsequence(string s, string t) {
        
       int n=s.length(),m=t.length();
    vector<int>prev(m+1,0);

    for(int i=0;i<=n;i++)prev[0]=0;
    // for(int j=0;j<=m;j++)dp[0][j]=0;

    for(int i=1;i<=n;i++){
        vector<int>curr(m+1,0);
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])curr[j]=1+prev[j-1];
            else curr[j]= max(curr[j-1],prev[j]);
        }
        prev=curr;
    }
    
    return  prev[m];
        
    }
};