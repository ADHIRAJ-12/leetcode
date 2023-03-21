class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length(),posn=-n;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
                if(s[i]==c) posn=i;
                ans[i]=(i-posn);

        }
         for(int i=n-1;i>=0;i--){
                if(s[i]==c) posn=i;
                ans[i]=min(ans[i],abs(i-posn));

        }
         
        return ans;
    }
};