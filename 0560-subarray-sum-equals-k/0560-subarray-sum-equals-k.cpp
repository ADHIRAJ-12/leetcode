class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    
        int n=nums.size();
        
            if (n==0)
            return 0;
        
            unordered_map<int,int>m;
            int currSum=0,i=0,count=0;
        
            while (i<n){
                
                currSum+=nums[i];
                if(currSum==k)
                    count++;
                    
                if(m.find(currSum-k)!=m.end())
                    count+=m[currSum-k];
                
                m[currSum]++;
                i++;
                
           }
            return count;
                
        }
    
};


     


//         int n=nums.size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             int sum=nums[i];
//             if(nums[i]==k)count++;
//              for(int j=i+1;j<n;j++){
//                  sum+=nums[j];
//                  if(sum==k)count++;
//              }
            
//         }
//             return count;
            