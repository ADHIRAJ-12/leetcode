class Solution {
public:
    
    bool isPalindrome(string s){
        int n=s.size();
       for(int i=0;i<n/2;i++){
           if(s[i]!=s[n-i-1])return false;
       }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        
        string ans="";
        for(int i=0;i<words.size();i++){
            if(isPalindrome(words[i])){
                ans=words[i];
                break;
            }
        }
        return ans;
    }
};