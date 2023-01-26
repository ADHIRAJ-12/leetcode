class Solution {
public:
    int thirdMax(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        
       set<int>s(nums.begin(),nums.end());
       if(s.size()<3)return *max_element(nums.begin(),nums.end());
       int t=s.size()-3;
       auto it=s.begin();
       while(t--){
           it++;
       }
       return *it;
    }
};