class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
      
        int n=nums.size(),xorr=0;
        int k=pow(2,maximumBit)-1;  
        vector<int>ans;
        
        for(int i=0;i<n;i++)xorr=xorr^nums[i];
        for(int i=n-1;i>=0;i--){
            ans.push_back(xorr^k);
            xorr=xorr^nums[i];
        }
        return ans;
    }
};