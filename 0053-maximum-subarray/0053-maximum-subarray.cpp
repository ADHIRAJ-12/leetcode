class Solution {
public:
    
//     kadane's algo;
    
    int maxSubArray(vector<int>& nums) {
        

        int maxi=nums[0],sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum<0)sum=0;
            sum+=nums[i];
            maxi=max(sum,maxi);
        }
        return maxi;
    }
};
    

    // int MAX = INT_MIN;
        // int sum = 0;
        // for(int i = 0; i < nums.size(); i++) {
        //     sum += nums[i];
        //     MAX = max(sum, MAX);
        //     if(sum < 0) sum = 0;
        // }
        // return MAX;