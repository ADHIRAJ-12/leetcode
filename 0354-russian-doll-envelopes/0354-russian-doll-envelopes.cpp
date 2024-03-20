class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    
     int solveBinary(int n,vector<int>& nums){
        
        if(n==0) return 0;
        
        vector<int>ans;
        ans.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            
         if(nums[i]>ans.back()) ans.push_back(nums[i]);
            
         else{
                //find index of just bda element
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
                return ans.size();
    }
    
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
         //similar to . Longest Increasing Subsequence
        //binarry search dp concept
        
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int>res;
        for(int i=0;i<=envelopes.size()-1;i++){
        res.push_back(envelopes[i][1]);
        }
        
        int s=res.size();
        return solveBinary(s,res);
    }
};