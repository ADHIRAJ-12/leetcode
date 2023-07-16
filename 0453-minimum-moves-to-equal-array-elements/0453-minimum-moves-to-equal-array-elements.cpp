class Solution {
public:
    int minMoves(vector<int>& nums) {
    int ans=0;
    int mini=*min_element(nums.begin(),nums.end());
    for(auto i:nums)ans+=i-mini; 
    return ans;
    }
};