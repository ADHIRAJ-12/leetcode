class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long ans=0,n=nums.size();
        for(int i=0;i<n;i++)if(n%(i+1)==0)ans=ans+(nums[i]*nums[i]);
        return ans;
    }
};