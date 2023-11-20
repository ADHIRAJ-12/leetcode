class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
          int ans=0;
          int i=0,j=0;     
         if(s.length()==0)return 0;
         if(s.length()==1)return 1;
        
        
        unordered_map<char,int>mp;

        while(j<s.length()){
                mp[s[j]]++;

                while(mp[s[j]]>1){
                    mp[s[i]]--;
                    i++;
                }
                 ans=max(ans,j-i+1);
                j++;
            }
            return ans;
        
    }
};