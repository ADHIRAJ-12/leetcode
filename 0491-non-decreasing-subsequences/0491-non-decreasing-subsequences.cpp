class Solution {
public:
    
    void solve(set<vector<int>>&ans,vector<int> &temp,vector<int> &nums,int n,int ind){
        if(ind>=n){
            if(temp.size()>=2)ans.insert(temp);
            return;
        }
        
        if(temp.size()==0 ||nums[ind]>=temp.back()){
            temp.push_back(nums[ind]);
            solve(ans,temp,nums,n,ind+1);
            temp.pop_back();
        }
       solve(ans,temp,nums,n,ind+1);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        set<vector<int>> ans;
        int n=nums.size();
        solve(ans,temp,nums,n,0);
        return vector(ans.begin(),ans.end());
    }
};