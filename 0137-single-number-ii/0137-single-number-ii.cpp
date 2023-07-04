class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)m[nums[i]]++;
        for(auto i:m)if(i.second!=3)ans= i.first;
        return ans;
    }
};