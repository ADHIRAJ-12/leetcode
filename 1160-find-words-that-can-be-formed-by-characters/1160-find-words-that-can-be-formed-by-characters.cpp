class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp1;
        for(int i=0;i<chars.length();i++)mp1[chars[i]]++;
        int count=0;
        for(int i=0;i<words.size();i++){
            string str1=words[i];
             unordered_map<char,int>mp2;
            for(int j=0;j<str1.size();j++){
                
                mp2[str1[j]]++;
                
                if(mp1[str1[j]]>=mp2[str1[j]])count++;
                else{
                   count-=j;
                    break;
                }
            }
            
        }
        return count;
        
    }
};