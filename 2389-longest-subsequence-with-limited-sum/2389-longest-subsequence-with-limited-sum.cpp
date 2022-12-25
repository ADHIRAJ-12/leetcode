class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n=nums.size();
        int m=queries.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
            int len=0;
       
        for(int i=1;i<n;i++)nums[i]=nums[i]+nums[i-1];
           
        for(int i=0;i<m;i++){
            int ind=upper_bound(nums.begin(),nums.end(),queries[i])-nums.begin();
            ans.push_back(ind);    
        }
            return ans;
    }
};