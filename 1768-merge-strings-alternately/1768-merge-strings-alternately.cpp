class Solution {
public:
    string mergeAlternately(string word1, string word2) {
     
        string ans="";
        int i=0,m=word1.length(),n=word2.length();
        while(i<m || i<n){
            if(i<m)ans+=word1[i];
            if(i<n)ans+=word2[i];
            i++;
        }
        return ans;
    }
};