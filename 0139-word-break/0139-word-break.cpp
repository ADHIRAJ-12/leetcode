class Solution {
public:
    
    
    map<string,int>m;
    unordered_set<string>st;
    
    bool solve(string s,vector<string> &word){
        
        if(st.find(s)!=st.end()) return true;
        if(m.find(s)!=m.end()) return m[s];
        
        for(int i=0;i<s.size();i++){
            
            string str=s.substr(0,i);
            if(st.find(str)!=st.end() and solve(s.substr(i),word)){
                m[s]=1;
                return true;
                }
        }
            m[s]=0;
            return false;
        
        
    }
    
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x:wordDict){
            st.insert(x);
            
        }
        
        return solve(s,wordDict);
    }
};