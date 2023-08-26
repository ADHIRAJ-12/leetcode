class DisjointSet{

    vector<int>parent,rank,size;

public:
    //constructor
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
        }
        else{
             parent[ultU]=ultV;
            size[ultV]+=size[ultU];
        }
    }

};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n>connections.size()+1)return -1;
        DisjointSet ds(n);
          for(int i=0;i<connections.size();i++){
            ds.unionBySize(connections[i][0],connections[i][1]);
        }
        
        int c=0;
        for(int i=0;i<n;i++)if(ds.findUltParent(i)==i)c++;
        return c-1;
        
        
    }
};