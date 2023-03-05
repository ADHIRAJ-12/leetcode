class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int n=nums.size();
        int prevMin=-1,prevMax=-1,startIndex=-1;
        long long ans=0;
        
        for(int i=0;i<n;i++){
         if(nums[i]<minK ||nums[i]>maxK) startIndex=i;
            
         if(nums[i]==minK)prevMin=i;

         if(nums[i]==maxK)prevMax=i;
            
         ans+=max(0,min(prevMin,prevMax)-startIndex);

        }
        
        return ans;
        
    }
};