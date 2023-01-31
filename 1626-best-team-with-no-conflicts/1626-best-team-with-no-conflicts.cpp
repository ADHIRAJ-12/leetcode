class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size(),sum;
        vector<pair<int,int>>p;
        vector<int>dp(n);
        
        for(int i=0;i<n;i++)p.push_back(make_pair(ages[i],scores[i]));
        sort(p.begin(),p.end());
        
        for(int i=0;i<n;i++){
            dp[i]=p[i].second;
            for(int j=0;j<i;j++){
                if(p[j].second<=p[i].second)dp[i]=max(dp[i],dp[j]+p[i].second);
            }
            sum=max(sum,dp[i]);
        }
        return sum;
    }
};