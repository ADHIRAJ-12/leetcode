class Solution {
public:
    
    
     bool canvisit(int node, int &target, vector<int> adj[], vector<int>&vis){ 
         
         vis[node]=1;
         if(node==target)return true;
         
         for(auto it: adj[node]){   
             if(!vis[it])
             if(canvisit(it, target, adj, vis))
             return true;
         }

         return false;       
    }
    
    
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        
        
        vector<bool>ans(queries.size(), false); 
        if(prereq.size()==0) return ans; 

        vector<int> adj[n];
        for(auto it: prereq){
            adj[it[0]].push_back(it[1]); 
        }
     
        for(int i=0; i<queries.size(); i++){
                vector<int>vis(n,0);
                if( canvisit( queries[i][0],queries[i][1],adj,vis) )ans[i]=true;
                else ans[i]=false;
        }

        return ans;
    }
};