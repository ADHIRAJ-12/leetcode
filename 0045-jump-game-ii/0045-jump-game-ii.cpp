class Solution {
public:
    int jump(vector<int>& nums) {
        
        //greedy solution
        int maximum=0,currmax=0,n=nums.size(),ans=0;
        
        for(int i=0;i<n-1;i++){
            currmax=max(currmax,i+nums[i]);
            if(i==maximum){
                ans++;
                maximum=currmax;
            }
        }
        return ans;
    }
};