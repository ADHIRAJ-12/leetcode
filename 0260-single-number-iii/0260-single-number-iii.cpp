class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)m[nums[i]]++;
        for(auto i:m)if(i.second==1)ans.push_back( i.first);
        return ans;
    }
};