class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans=0,ans2=0,n=nums.size();
        
        for(int i=1;i<n;i++){
            int diff=nums[i]-nums[i-1];
            
            if(diff>0  )ans=ans2+1;
            if(diff<0 )ans2=ans+1;
            
        }
     int anss= max(ans,ans2);   
        return anss+1;
//     int n=nums.size();
//     int p=0,q=0;
//     for(int i=1;i<n;i++)
//     {
//        if(nums[i]>nums[i-1])p=q+1;
//         else if(nums[i]<nums[i-1])q=p+1;

//     }
//     int ans= max(p,q);
//     return ans+1;
    }
};