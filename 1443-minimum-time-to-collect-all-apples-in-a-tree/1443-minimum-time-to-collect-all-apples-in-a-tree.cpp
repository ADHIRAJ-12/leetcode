class Solution {
public:
    
    bool dfs(int start,int p,int &count,vector<int>adj[],vector<bool>& hasApple){
       
       bool flag=hasApple[start];
        for(int nbr:adj[start]){
            if(nbr!=p){
                bool applePresent=dfs(nbr,start,count,adj,hasApple);
                if(applePresent)count+=2;
                flag=(flag||applePresent);
            }
        }
        return flag;
     }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //dfs
        vector<int>adj[n];
        int count=0;
        for(vector<int>i:edges){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,count,adj,hasApple);
        return count;
    }
};