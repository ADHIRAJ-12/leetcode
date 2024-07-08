class Solution {
public:
    string getEncryptedString(string s, int k) {
        
        string ans;    
        k = k%s.size();
        for (int i=0;i<s.size();i++){
            int index=(i+k)%s.size();
            ans+=s[index];
        }
        return ans;
    }
};