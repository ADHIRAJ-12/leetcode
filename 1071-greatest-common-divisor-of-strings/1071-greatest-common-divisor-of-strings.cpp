class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        int n=str1.size();
        int m=str2.size();        
        int gcd=__gcd(n,m);
        string subst=str1.substr(0,gcd);
        
        //condition for gcd to exist
        if(str1+str2!=str2+str1)return "";
        else return subst;       
    }
};