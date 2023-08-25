class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        
        //preparing adj matrix
        
        vector<vector<int>>adj(n,vector<int>(n,1e9));
        for(auto i : edges){
            adj[i[0]][i[1]] = i[2];
            adj[i[1]][i[0]] = i[2];
        }
        for(int i=0;i<n;i++) adj[i][i]=0;
        
        // floyd warshall
        
         for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                 if((adj[i][j] > adj[i][via] + adj[via][j]) && adj[i][via] !=1e9 && adj[via][j] !=1e9){
                        adj[i][j] = adj[i][via] + adj[via][j];
                    }
                }
            }
        }
        // vector storing no of nodes reachable form node at index i
        vector<int>reachableFromIndex(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(adj[i][j]<=th)reachableFromIndex[i]++;
            }
        }
        
        //node with which we can reach minimum number of nodes
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
          mini=min(mini,reachableFromIndex[i]);
        }
        
        //nif multiple nodes exists ,findinf one with largest number
       int maxIndexOfSameMini=-1;
        for(int i=0;i<n;i++){
            if(reachableFromIndex[i]==mini)maxIndexOfSameMini=max(maxIndexOfSameMini,i);
        }
        
        return maxIndexOfSameMini;
        
    }
};