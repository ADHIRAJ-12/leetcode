class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-1;i++){
        if(i>0 && nums[i]==nums[i-1])continue;
            int temp=nums[i], s=i+1,e=n-1;
            while(s<=e){
                
                int mid=(s+e)>>1;
                if(nums[mid]-temp==k){
                    count++;
                    break;
                }
                else if(nums[mid]-temp>k)e=mid-1;
                else s=mid+1;
            }
        }
        return count;
    }
};