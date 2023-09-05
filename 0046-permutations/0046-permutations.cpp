class Solution {
public:
    
    
    void f(int ind,vector<int>&nums,vector<int>&vis,vector<int>&temp,vector<vector<int>>&ans){
        
        
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                temp.push_back(nums[i]);
                vis[i]=1;
                f(i+1,nums,vis,temp,ans);
                vis[i]=0;
                temp.pop_back();
            }
        }
        
        
        
    }
    
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        //method 1 using extra space
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>vis(nums.size(),0);
        
        f(0,nums,vis,temp,ans);
        return ans;

        
    }
};