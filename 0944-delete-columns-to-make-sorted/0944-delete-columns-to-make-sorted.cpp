class Solution {
public:
    
    bool sorted(int col,int n,vector<string>& strs){
    for(int i=1;i<n;i++){
        if(strs[i-1][col]>strs[i][col])return false;
        }
        return true;
    }
    
    
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int ans=0;
        //check sorted columns
        for(int i=0;i<m;i++){
            if(!sorted(i,n,strs))ans++;
        }
        return ans;
    }
};