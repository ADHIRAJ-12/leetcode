class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     int n=nums.size();
        if(n==0)return 0;
        
        int s=0,e=n-1;
        while(s<e){
           int mid=s+(e-s)/2;
            
            
            if(nums[mid]==target) return mid;
            
            else if(target<nums[mid]) e=mid;
            
            else s=mid+1;
            
        }
    return nums[s]<target?s+1:s;
    }
};