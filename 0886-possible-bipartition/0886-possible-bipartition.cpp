class Solution {
public:
    bool dfs(vector<vector<int>> &adj,int node,int grup,vector<int> &groups){
        
        groups[node]=grup;
        for(auto i :adj[node]){
            if(groups[i]==groups[node])return false;
            
            if(groups[i]==0 && !dfs(adj,i,-grup,groups))return false;
        }
     
        return true;
        
      }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>>adj(n+1);
        
        
        for(auto i :dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int>groups(n+1,0);
        //assume that the group 0 means ungrouped
        //1 means that it is a member of group 1
        // -1 means that is the member of the group 2
        for(int i=0;i<n;i++){
            if(groups[i]==0 && !dfs(adj,i,1,groups))return false;
            //means that if the node is iniatailly unpartioned and after putting it in the grup one and calling dfs if the output comes as false 
            // then it is not possible to bi partioton thr node
        }
        return true;
        
    }
};