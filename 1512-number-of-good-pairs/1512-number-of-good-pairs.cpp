class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

    // int n=nums.size(),count=0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(nums[i]==nums[j])count++;        }
    // }    
    // return count;

    unordered_map<int,int>mp; 
         
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;  
           
        int count= 0;
        for(auto i:mp) {
            int n = i.second; 
            count += ((n)*(n-1))/2;
            
        }
        return count;
    }
};