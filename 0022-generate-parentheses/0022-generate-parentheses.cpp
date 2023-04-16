class Solution {
public:
    
    void solve(vector<string> &ans,string &s,int open,int close){
        //base case
        if(open==0 && close==0)ans.push_back(s);
        
        //if open brackets are present
        if(open>0){
            s.push_back('(');
            solve(ans,s,open-1,close);
            //backtrack
            s.pop_back();
        }
        //if close brackets are present and count of close in ans-string is less than open OR count of close bracket left are greater than open
        if(close>0){
            if(open<close){
                 s.push_back(')');
            solve(ans,s,open,close-1);
                //backtrack
            s.pop_back();
            }
        }
        
    
}
    
    vector<string> generateParenthesis(int n) {
     vector<string>ans;
        string s;
        solve(ans,s,n,n);
        return ans;
    }
};