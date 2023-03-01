class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       //sort(nums.begin(),nums.end());
      
        int n=nums.size();
        priority_queue<int,vector<int> , greater<int> > mini;
        for(int i=0;i<n;i++){
            mini.push(nums[i]);
        }
    
        vector<int>ans;
        int m = mini.size();
        for(int i=0;i<m;i++){
            ans.push_back(mini.top());
            mini.pop();
        }
        return ans;
   
        }
};