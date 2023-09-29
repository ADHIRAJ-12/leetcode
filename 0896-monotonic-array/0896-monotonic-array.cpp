class Solution {
public:
    
    bool inc(vector<int>& nums){
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i])return false;
        }
        return true;
    }
     bool dec(vector<int>& nums){
        
         reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i])return false;
        }
        return true;
    }
    
    bool isMonotonic(vector<int>& nums) {
      
        if (inc(nums))return true;
        return dec(nums)?true:false;
        
    }
};