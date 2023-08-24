class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int>dist(n,1e9);
        dist[src]=0;
        vector<vector<int>>adj[n];
        
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

//k,price,src
        queue<pair<int,pair<int,int> > >mini;
        mini.push({0,{0,src}});
        
        while(!mini.empty()){
            
            int count=mini.front().first;
            int price=mini.front().second.first;
            int node=mini.front().second.second;
            mini.pop();
            
            // if(node==dst &&count<=k+1 )return price;
            // count++;
            if(count>k)continue;
            for(auto i:adj[node]){
                
                int wt=i[1];
                int nbr=i[0];
                if(price+wt<dist[nbr] &&count<=k)  {
                    int newprice=price+wt;
                    dist[nbr]=newprice;
                    mini.push({count+1,{newprice,nbr}});
                }
            
         }

            
        }
        if(dist[dst]==1e9)return -1;
        else return dist[dst];
        
        
    }
};