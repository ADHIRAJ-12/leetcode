class Solution {
public:
    
    bool inc(vector<int>& nums){
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i])return false;
        }
        return true;
    }
 
    
    bool isMonotonic(vector<int>& nums) {
      
        if (inc(nums))return true;
         reverse(nums.begin(),nums.end());
        return inc(nums)?true:false;
        
    }
};