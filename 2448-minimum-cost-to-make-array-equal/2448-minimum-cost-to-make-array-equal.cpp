class Solution {
public:
    
    long solve(vector<int>& nums, vector<int>& cost,int curr){
        
        //cur=wo element jiske equal hu pur array ko banan anch ate hai currently
        
        long ans=0L;
        for(int i=0;i<nums.size();i++){
            ans+=1L*abs(nums[i]-curr)*cost[i];
            
        }
        return ans;
        
    }
    
    
    long long minCost(vector<int>& nums, vector<int>& cost) {       
    
    //optimal solution by binary search
     int mini = nums[0],maxi = nums[0];
        long ans=0;
        for (int i : nums) {
            mini = min(mini, i);
            maxi= max(maxi, i);
        }
        while(mini<maxi){
            
            int mid=(maxi+mini)/2;
            long  cost1=solve(nums,cost,mid);
            long cost2=solve(nums,cost,mid+1);
            
            if(cost1>cost2){
                mini=mid+1;
                ans=cost2;
            }
            else{
                maxi=mid;
                ans=cost1;
            }

        }
return ans;
        
        
    }
};

        
//         int n=nums.size();
//         int m=cost.size();
//         int ind=0;
//         long long target=*max_element(cost.begin(),cost.end());
//         for(long i=0;i<m;i++){
//             if(cost[i]==target)ind=i;
//         }
//        for(long i=0;i<n;i++) 
//        {
//            long long cos=(abs(nums[i]-nums[ind]));
//            long long temp=cos*cost[i];
//            ans+=temp;
//        }
//         return ans;