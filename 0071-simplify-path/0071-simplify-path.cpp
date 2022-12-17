class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        stack<string>s;
        string ans;
        
        for(int i=0;i<n;i++){
            if(path[i]== '/')continue;
            string str;
            while(i<n && path[i]!='/'){
                str+=path[i];
                i++;
            }
            if(str==".")continue;
            
           if(str==".."){
               if(!s.empty())s.pop();
           }
            
            else s.push(str);

        }
        
        while(!s.empty()){
            ans="/"+s.top()+ans;
            s.pop();
        }
        
        if(ans.size()==0)return "/";
        
        return ans;
    }
};