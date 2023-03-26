class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        vector<int>temp=intervals[0];
        
        if(intervals.size()==0)return ans;
        for(auto interval:intervals){
            if(interval[0]<=temp[1]){
                temp[1]=max(temp[1],interval[1]);
            }
            else{
                ans.push_back(temp);
                temp=interval;
            }
        }
        ans.push_back(temp);
        return ans;
        
        
        
    }
};