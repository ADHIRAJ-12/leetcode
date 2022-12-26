class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
     
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int count=0;
        vector<vector<int>>temp;
        
        for(int i=n-1;i>=0;i--){
            
            if(temp.empty()  ||temp.back()[0]>=intervals[i][1])temp.push_back(intervals[i]);
            
           // else if(temp.back()[0]>=intervals[i][1])temp.push_back(intervals[i]);
            
            else count++; //if(inetrval is overlapping)

        }
        return count;
        
    }
};