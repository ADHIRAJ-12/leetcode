class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& matrix) {
          for(auto &row:matrix)sort(row.begin(), row.end());
        
    int count=0,index=-1,n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
        vector<int>arr=matrix[i];
        int ones=m-(lower_bound(arr.begin(),arr.end(),1)-arr.begin());
        if(ones>count){
            count=ones;
            index=i;
        }
    }
        if(index==-1)index=0;
         return {index,count};
    }
};