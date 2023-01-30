class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans,temp,temp1;
        
        for(int i=0;i<n;i++){
                if(nums[i]%2==0)temp.push_back(nums[i]);
                if(nums[i]%2!=0)temp1.push_back(nums[i]);
            }
        int m =temp.size();
        for(int i=0;i<m;i++){
            ans.push_back(temp[i]);
            ans.push_back(temp1[i]);
        }
        return ans;
    }
};