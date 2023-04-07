class Solution {
public:
    
    static bool cmp(pair<int,int>&a, pair<int,int>&b) {
        return (a.second==b.second) ? a.first>b.first : a.second<b.second;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums;
        
        vector<int>ans(n);
        unordered_map<int,int>m;
         vector<pair<int,int>> freq;
        for(int i=0;i<n;i++)m[nums[i]]++;
        
        for(auto i:m)freq.push_back(i);
        sort(freq.begin(),freq.end(),cmp);
        vector<int> res;
        for(auto value: freq) {
            for(int i=0;i<value.second;i++) {
                res.push_back(value.first);
            }
        }
        return res;

            
    }
};