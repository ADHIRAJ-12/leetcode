class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int n=points.size();
        
        int index = points[0][1];
        int count=0;
        for(int i=0;i<n;i++){
            if(points[i][0]<=index)continue;
            else{
                count++;
                index= points[i][1];
            }
        }
        count++;   
        return count;
    }
};