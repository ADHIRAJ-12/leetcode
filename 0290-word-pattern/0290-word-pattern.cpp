class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=s.size(),i=0;
        string temp="";
        vector<string>words;
        //creating a vector having all words
        while(i<n){
            if(s[i]==' '){
                words.push_back(temp);
                temp="";
            }
            else{
                temp+=s[i];
            }
            i++;
        }
        words.push_back(temp);
        
        if(words.size()!=pattern.size())return false;
        
        unordered_map<char,string>m;
        set<string>myset;
        for(int i=0;i<pattern.size();i++){
            if(m.find(pattern[i])!=m.end()){
                if(m[pattern[i]]!=words[i])return false;
            }
            else{
                if(myset.count(words[i])>0)return false;
                m[pattern[i]]=words[i];
                myset.insert(words[i]);
            }
        }
        return true;
    }
};