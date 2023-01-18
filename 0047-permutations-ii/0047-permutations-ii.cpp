class Solution {
public:


void solve(vector<int> nums,  vector<vector<int>>& ans,int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>s;
        for(int j=index;j<nums.size();j++){
            if(s.find(nums[j])!=s.end()) continue;
            s.insert(nums[j]);
            swap(nums[index],nums[j]);
            solve(nums,ans,index+1);
            //backtracking
            swap(nums[index],nums[j]);

        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>>ans;
        int index=0;
        solve(nums,ans,index);
        return ans;   
    }
};