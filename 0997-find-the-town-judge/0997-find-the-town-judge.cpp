class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int>istrustedby(n+1,0);
        vector<int>trusts(n+1,0);
        int m=trust.size();
        for(int i=0;i<m;i++){
            trusts[trust[i][0]]++;
            istrustedby[trust[i][1]]++;
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(trusts[i]==0 &&istrustedby[i]==n-1)ans=i;
        }
        return ans;
    }
};