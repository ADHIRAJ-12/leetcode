class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size(),m=mat[0].size();
    int s=0,e=(n*m)-1;

    while(s<=e){
        int mid=s+(e-s)/2;
        int row=mid/m,col=mid%m;
        if(mat[row][col]==target)return true;
        else if(mat[row][col]>target)e=mid-1;
        else s=mid+1;
    }
    return false;
    }
};