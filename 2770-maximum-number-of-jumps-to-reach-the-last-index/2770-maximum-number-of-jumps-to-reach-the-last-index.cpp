class Solution {
public:
   int solve(vector<int>& nums, int& target, int ind, int prev, vector<int>& dp){
    int n=nums.size();
    if(ind == n-1) return 0;
    if(dp[ind] != INT_MIN) return dp[ind];
    
    int res = -1;
    for(int j = ind+1; j <n; ++j){
        if(abs(nums[j] - prev)<= target) {
            int take = solve(nums, target, j, nums[j], dp);
            if(take != -1) res = max(res,1+take);
        }
    }
    return dp[ind] = res;
}
    
int maximumJumps(vector<int>& nums, int target) {
    int n=nums.size();
    vector<int> dp(n, INT_MIN);
    return solve(nums, target, 0, nums[0], dp);
    }
};