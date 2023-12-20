class Solution {
public:
    int buyChoco(vector<int>& nums, int money) {
        sort(nums.begin(),nums.end());
        if(money-(nums[0]+nums[1])>=0)return money-(nums[0]+nums[1]);
        return money;
    }
};