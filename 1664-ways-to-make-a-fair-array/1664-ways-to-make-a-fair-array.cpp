class Solution {
public:
        
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int>odd(n),even(n);
        int oddsum=0,evensum=0;
        
        for(int i=0;i<n;i++){
            if(i%2==0)evensum+=nums[i];
            else oddsum+=nums[i];
            even[i]=evensum;
            odd[i]=oddsum;
        }
        
         ans=0;
        for(int i=0;i<n;i++){
            if(i==0){
                int nos=even[n-1]-nums[0];
                int nes=odd[n-1];
                if(nos==nes)ans++;
                continue;
            }
            
            
            int nos=odd[i-1]+even[n-1]-even[i];
            int nes=even[i-1]+odd[n-1]-odd[i];
            if(nos==nes)ans++;
            
        }
        
        return ans;
        
    }
};