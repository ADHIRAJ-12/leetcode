class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        int ans;
        
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        for(auto i:m){
            if(i.second==1)ans=i.first;
        }
        return ans;
        
    }
};