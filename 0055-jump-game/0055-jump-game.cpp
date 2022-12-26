class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        int maxReach=0;
        
        for(int currIndex=0;currIndex<n;++currIndex){
            
            if(maxReach<currIndex) return false;
            
            maxReach=max(maxReach,currIndex+nums[currIndex]);
        }
        return true;
    }
};