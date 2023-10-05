class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector <int>ans; 
            
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(m[nums[i]]>n/3 && find(ans.begin(), ans.end(), nums[i]) == ans.end())                                  ans.push_back(nums[i]);
        
        }
        
        return ans;
    }
};