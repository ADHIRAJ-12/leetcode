class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>count(k,0);
        int sum=0;
        for(int i:nums){
            sum+=(i%k+k)%k;
            count[sum%k]++;
        }
        int result=count[0];
        for(int j:count)
            result+=(j*(j-1))/2;
            return result;
        
    }
};