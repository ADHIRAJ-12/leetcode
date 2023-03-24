class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
                
        int n=nums.size();
        vector<int>ans(n);
        int even=0,odd=1;
        
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                ans[even]=nums[i];
                even+=2;
            }
            else{
                ans[odd]=nums[i];
                odd+=2;
            }
        }
           return ans;
            }
};
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         int n=nums.size();
//         vector<int>positive;
//         vector<int>negative;
//         vector<int>ans(n);
        
//         for(int i=0;i<n;i++){
//             if(nums[i]>=0)positive.push_back(nums[i]);
//             else negative.push_back(nums[i]);
//         }
        
//         for(int i=0;i<n/2;i++){
//             ans[2*i]=positive[i];
//            ans[2*i+1]=negative[i];           
//         }
//         return ans;
