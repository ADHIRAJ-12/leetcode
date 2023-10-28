class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int result=0;
        int n=nums.size();
        int min_diff=INT_MAX;
        
        for(int i=0;i<n-2;i++){
            
            int left=i+1;
            int right=n-1;
            
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                
                if(abs(target-sum )< min_diff) min_diff=abs(target-sum), result=sum;
                
                if(sum>target) right--;
                
                else left++;
            }
            
        }

return result;
        
    }
};