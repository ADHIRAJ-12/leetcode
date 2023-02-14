class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        
        int n=nums.size();
        long long res=0;
         for(int i= 0; i< n/2;i++){
            string s=to_string (nums[i])+to_string (nums[n-i-1]);
            res+=stoi(s);
         }
           if(n%2)res+=nums[n/2];
           return res;
        
    }
};