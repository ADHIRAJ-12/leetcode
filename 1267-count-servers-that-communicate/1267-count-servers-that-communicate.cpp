class DisjointSet{


public:
    //constructor
        vector<int>parent,rank,size;

     DisjointSet(int n){

        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }


     }

    int findUltParent(int node){
        if(node==parent[node])return node;
        else return parent[node]=findUltParent(parent[node]);
    }


    void unionByRank(int u,int v){

        int ultU=findUltParent(u);
        int ultV=findUltParent(v);

        if(ultV==ultU)return;
        if(rank[ultV]<rank[ultU])parent[ultV]=ultU;
        else if(rank[ultU]<rank[ultV])parent[ultU]=ultV;
        else {
            parent[ultV]=ultU;
            rank[ultU]++;
        }
    }


    void unionBySize(int u,int v){

        int ultU=findUltParent(u);
        int ultV=findUltParent(v);

        if(ultV==ultU)return;
        if(size[ultV]<size[ultU]){
            parent[ultV]=ultU;
            size[ultU]+=size[ultV];
            size[ultV] = 0;
        }
        else{
             parent[ultU]=ultV;
            size[ultV]+=size[ultU];
            size[ultU] = 0;
        }
    }

};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
         DisjointSet ds(n*m);
        
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) {
                int currColm=i*m+j;
                //ceeck for a server in this column
                while(j<m){
                    if(grid[i][j]==1){
                        int nbrOne=i*m+j;
                        ds.unionBySize(currColm,nbrOne);
                    }
                    j++;
                }
                
            }
        }
      }
        
        
           for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(grid[i][j] == 1) {
                int currRow=i*m+j;
                //check for a server in this row
                while(i<n){
                    if(grid[i][j]==1){
                        int nbrOne=i*m+j;
                        ds.unionBySize(currRow,nbrOne);
                    }
                    i++;
                }
                
            }
        }
      }
        
        int ans=0;
        for(int i=0;i<=(m*n);i++){
            if(ds.size[i]>1)ans+=ds.size[i];
        }
        return ans;
        
        
        
    }
};