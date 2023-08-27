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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        
        //make dsu 
        int n=accounts.size();
         DisjointSet ds(n);
        
        unordered_map<string,int>mp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                int node=i;
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=node;
                }
                else{
                    ds.unionBySize(node,mp[mail]);
                }
            }
        }
        
        vector<string>mergedMail[n];
        for(auto i:mp){
            string mail=i.first;
            int par=ds.findUltParent(i.second);
            mergedMail[par].push_back(mail);
        }
        
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0)continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
        
        
    }
};