class Solution {
public:
    
    void f(int ind,int count,int k,int target,int n,vector<int>&nums,vector<int>&res,vector<vector<int>>&ans){
        
        //base
        if(target==0 && count==k ){
            ans.push_back(res);
            return;
        }
        
        for(int i=ind;i<n;i++){
            
            //not take
            if(nums[i]>target)break;
            
             // if(i>ind && nums[i]==nums[i-1])continue;

                res.push_back(nums[i]);
                count++;
                f(i+1,count,k,target-nums[i],n,nums,res,ans);
                res.pop_back();
                count--;

        
            }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int target) {
        
         vector<vector<int>>ans;
         vector<int>res;
        vector<int>nums={1,2,3,4,5,6,7,8,9};
    //ind,count,k,targeet,size of nums,nums,ans,res
        f(0,0,k,target,9,nums,res,ans);
        return ans;
        
    }
};