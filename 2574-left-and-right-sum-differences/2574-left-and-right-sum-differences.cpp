class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        
        int totalSum = 0, leftSum = 0;
        vector<int>ans;
        for (int i=0;i<nums.size();i++) totalSum  += nums[i];
        for(int i = 0; i < nums.size(); i++){
            int rightSum = totalSum - (leftSum + nums[i]);
            ans.push_back(abs(rightSum - leftSum));
            leftSum += nums[i];
        }
        return ans;
    }
};