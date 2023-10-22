class Solution {
public:
    int maximumWealth(vector<vector<int>>& nums) {
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int temp=0;
            for(int j=0;j<nums[0].size();j++){
                temp+=nums[i][j];
                ans=max(ans,temp);
            }

        }
        return ans;
    }
};