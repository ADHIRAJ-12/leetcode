class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
//         unordered_map<int,int>m;
//         int n=nums.size();
//         int ans;
        
//         for(int i=0;i<n;i++){
//             m[nums[i]]++;
//         }
        
//         for(auto i:m){
//             if(i.second==1)ans=i.first;
//         }
//         return ans;
        
         int n=nums.size();
        int s=0,e=n-1;
        
        while(s<e){
            int mid=s+(e-s)/2;
            if(mid%2==0 && nums[mid]==nums[mid+1] ||mid%2!=0 && nums[mid]==nums[mid-1])s=mid+1;
            
            else e=mid;
        }
        return nums[s];
        
    }
};