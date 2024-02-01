class Solution {
public:
    
    bool solve(int ind,vector<int>&nums,vector<int>&temp ,int k){
        if(nums[ind+2]-nums[ind]<=k){
            temp.push_back(nums[ind]);
            temp.push_back(nums[ind+1]);
            temp.push_back(nums[ind+2]);
            return true;

        }
        return false;
    }
    
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
         vector<vector<int>>ans;
        
        if(n%3!=0)return {};
       
        for(int i=0;i<n-2;i+=3){
            vector<int>temp;
            if(solve(i,nums,temp,k))ans.push_back(temp);
            else return {};
            
        }    
     
        return ans;   
    }
};