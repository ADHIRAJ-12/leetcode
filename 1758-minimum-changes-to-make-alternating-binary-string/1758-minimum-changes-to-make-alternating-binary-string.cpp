class Solution {
public:
    
    int check(string s){
        int ans=0;
        char last=s[0];
        
        for(int i=1;i<s.length();i++){
            if(s[i]==last){
                ans++;
                last=(s[i]=='0'?'1':'0');
            }
            else last=s[i];
        }
        return ans;
        
    }
    
    int minOperations(string s) {
        
        int a=check(s);
        s[0]=(s[0]=='0'?'1':'0');
        int b=1+check(s);
        return min(a,b);
    }
};