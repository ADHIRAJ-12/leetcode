class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int s=0,n=nums.size(),e=n-1,ans1=0,ans2=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]<0){
                ans1=mid+1;
                s=mid+1;
            }
            else e=mid-1;
            
        }
    s=0,e=n-1;
    while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>0){
                ans2=n-mid;
                e=mid-1;
            }
            else s=mid+1;
            
        }
        return max(ans1,ans2);
    }
};