class Solution {
public:
    
    
    int dfs(int root,vector<int>&vis,int sum,int maxi,vector<int>&moves){
        
        vis[root]=1;
        if(root==sum)return 1;
        
        for(int i=0;i<4;i++){
            int newroot=root+moves[i];
            if(newroot<=maxi && newroot>=0   && !vis[newroot] ){
                if(dfs(newroot,vis,sum,maxi,moves))return 1;
            }
        }
        
        return 0;
        
    }
    
    
    bool canMeasureWater(int jug1, int jug2, int sum) {
        
        int maxi=jug1+jug2;
        vector<int>vis(maxi+1,0);
        vector<int>moves={jug1,0-jug1,jug2,0-jug2};
        return dfs(0,vis,sum,maxi,moves);
        
        
        
        
    }
};