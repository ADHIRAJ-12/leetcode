class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>&nums ) {
        int n=nums.size(),m=nums[0].size();
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int sum=nums[i][j];
                int count=1;
                for(int k=0;k<dir.size();k++){
                    int nrow=i+dir[k][0];
                    int ncol=j+dir[k][1];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol <m){
                        sum+=nums[nrow][ncol];
                        count++;
                    }
                      

                }
                ans[i][j]=sum/count;
               
            }
          
            
        }

        return ans;

    }
};


