class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {

        int i=0,j=0,sum=0,len=INT_MAX,n=nums.size();

        while(j<n){

        sum+=nums[j];

        if(sum<target)j++;

        if(sum>=target){
            while(sum>=target){
                len=min(len,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;

          }
        } 
        return (len==INT_MAX)?0:len;   
    }
};