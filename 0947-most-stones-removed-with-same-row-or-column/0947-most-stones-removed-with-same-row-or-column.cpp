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
        }
        else{
             parent[ultU]=ultV;
            size[ultV]+=size[ultU];
        }
    }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int maxrow=0,maxcol=0;
        for(auto i:stones){
            maxrow=max(maxrow,i[0]);
            maxcol=max(maxcol,i[1]);
        }
        
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int>mp;
        for(auto i:stones){
            int row=i[0];
            int col=i[1]+1+maxrow;
            ds.unionBySize(row,col);
            mp[row]=1;
            mp[col]=1;
        }
        int c=0;
        for(auto i:mp){
            if(ds.findUltParent(i.first)==i.first)c++;
        }
        return stones.size()-c;
        
    }
};
















