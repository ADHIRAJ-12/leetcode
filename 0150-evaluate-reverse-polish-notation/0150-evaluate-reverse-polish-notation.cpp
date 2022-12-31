class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>s;
        int n=tokens.size();
        
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
              long a=s.top();
              s.pop();
              long b=s.top();
              s.pop();
              if(tokens[i]=="+")b+=a;
              if(tokens[i]=="-")b-=a;
              if(tokens[i]=="/")b/=a;
              if(tokens[i]=="*")b*=a;
              
              s.push(b);
            }
            else s.push(stoi(tokens[i]));
        }
        return s.top();
    }
};