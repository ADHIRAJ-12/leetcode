class Solution {
public:
    int ans;
    void solve(int ind,vector<int>& cookies,  vector<int> &bags){
        
        //base case
        if(ind==cookies.size()){
            int m=INT_MIN;
            for(int i=0;i<bags.size();i++){
                m=max(bags[i],m);
            }
            ans=min(ans,m);
            return;
        }
        
        //processing
        for(int j=0;j<bags.size();j++){
                bags[j]+=cookies[ind];          //take
                solve(ind+1,cookies,bags);    //process
                bags[j]-=cookies[ind];         //remove
        }
        
        
        
    }
    
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>bags(k,0);
        ans=INT_MAX;
        solve(0,cookies,bags);
        return ans;
    }
};