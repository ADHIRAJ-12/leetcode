class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(),nums.end());
        int ans,n=nums.size(),s=0,e=nums[n-1]-nums[0];
        while(s<=e){
            int mid=s+(e-s)/2;
            int count=0;
            for(int i=0;i<n-1;i++){
                if(nums[i+1]-nums[i]<=mid){
                    count++;
                    i++;
                }
            }
            
            if(count>=p){
                ans=mid;
                e =mid-1;
            }
            else s=mid+1;
            
        }
        return ans;
        
        
    }
};

     //    int n=nums.size();
     //    priority_queue<int,vector<int>,greater<int>>mini;
     //    for(int i=0;i<n;i++){
     //        for(int j=i+1;j<n;j++){
     //            mini.push(abs(nums[i]-nums[j]));
     //        }
     //    }
     //    int ans=0;
     //    while(p--){
     //        ans=max(ans,mini.top());
     //        mini.pop();
     //    }
     // return ans;   
        
        