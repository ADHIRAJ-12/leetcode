class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      
         vector<int>ans;
        int n=nums.size();
        
        //repeating =a
    sort(nums.begin(),nums.end());
    int a=-1,b=-1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]){
           a=nums[i];
            ans.push_back(a);
           break;
        }
        
    } 
    
   //missing =b
    int sum=0;
    int targetSum=n*(n+1)/2;
    
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
        
    b=targetSum-sum+a;
        ans.push_back(b);
    
    return ans;
    }
};