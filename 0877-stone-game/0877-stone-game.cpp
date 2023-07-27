class Solution {
public:
    bool stoneGame(vector<int>& nums) {
     
        int n=nums.size(),a=0,b=0;
        int i=0,j=n-1;
        while(i<j){
            if(nums[i]>nums[j]){
                a+=nums[i];
                b+=nums[j];
                i++;
                j--;
            }
          
            else{
                a+=nums[j];
                b+=nums[i];
                i++;
                j--;
            }
            
        }
        if(a>b)return true;
        else return false;
            
    }
};