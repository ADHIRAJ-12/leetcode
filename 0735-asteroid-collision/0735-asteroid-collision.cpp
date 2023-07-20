class Solution {
public:
    
    bool sign(int a,int b){
        if(a>0 && b>0)return true;
        else if (a<0 && b<0)return true;
        else return false;
    }
    
    vector<int> asteroidCollision(vector<int>& ast) {
        int n=ast.size();
        stack<int>s;
        for(int i=0;i<n;i++){
            if(s.size()==0 || (s.top()<0 && ast[i]>0)|| sign(s.top(),ast[i]) )s.push(ast[i]);
            else{
                
                while(s.size()>0 && s.top()>0 && s.top()<abs(ast[i]))s.pop();
                if(s.size()==0 || s.top()<0)s.push(ast[i]);
                else if(s.top() == abs(ast[i]))s.pop(); 
            }
        }
         
        vector<int> ans(s.size());
        int i=s.size()-1;
        while(!s.empty()){
            ans[i]=s.top();
            i--;
            s.pop();
        }
        return ans;
        
    }
};