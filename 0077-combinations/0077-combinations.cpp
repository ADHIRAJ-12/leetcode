class Solution {
public:

  void f(int ind,int k,vector<int> &temp,int n, vector<vector<int>> &ans){
      
     if(temp.size()==k){
         ans.push_back(temp);
         return;
     }
      
      for(int i=ind;i<n+1;i++){
        temp.push_back(i);
        f(i+1,k,temp,n,ans);
        temp.pop_back();
        
      }
  }

    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>ans;
        vector<int>temp;
         f(1,k,temp,n,ans);
         return ans;

    }
};