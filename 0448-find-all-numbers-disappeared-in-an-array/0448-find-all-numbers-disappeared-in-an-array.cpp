class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
     
        unordered_map<int,int> mp;
      // sort(nums.begin(), nums.end());
       vector<int> ans;
       for (auto i: nums)mp[i]++;
       
       for (int i = 1; i <= nums.size(); i++){
         if(mp.find(i)==mp.end())ans.push_back(i); 
       }
       return ans;
    }
};