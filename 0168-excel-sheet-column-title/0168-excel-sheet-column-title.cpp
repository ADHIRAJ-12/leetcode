class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int n= columnNumber;
        string ans="";
        while(n>0){
            n=n-1;
            int left= n%26;
            ans.push_back(s[left]);
            n=n/26;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};