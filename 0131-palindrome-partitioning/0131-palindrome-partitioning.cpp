class Solution {
public:
    
    
    bool palin(string&s ,int st,int e){
        
        while(st<=e){
            if(s[st]!=s[e])return false;
            else{
                st++;
                e--;
            }
        }
        return true;
        
    }
    
    void f(int ind,string &s,vector<string>&temp,vector<vector<string>>&ans){
        
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=ind;i<s.size();i++){
            
                if(palin(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,temp,ans);
                temp.pop_back();
            }
            
        }
        
        
    }
    
    
    
    
    
    vector<vector<string>> partition(string s) {
        
         vector<vector<string>>ans;
        vector<string>temp;
        f(0,s,temp,ans);
        return ans;
        
        
    }
};