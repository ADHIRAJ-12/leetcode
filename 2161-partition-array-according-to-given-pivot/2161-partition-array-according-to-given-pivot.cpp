class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);

        int low=0,equal=0,high;
        for(auto num:nums){
            if(num<pivot)++low;
            else if(num==pivot)++equal;
        }
        high=low+equal;
        equal=low;
        low=0;
        
        for(auto num:nums){
            if(num<pivot) ans[low++]=num;
            else if(num==pivot) ans[equal++]=num;
            else ans[high++]=num;
        }
        return ans;
    }
};