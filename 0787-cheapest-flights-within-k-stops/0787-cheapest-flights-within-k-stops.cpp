class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int>dist(n,-1);
        vector<int>temp(n);
        dist[src]=0;

        for(int i=0;i<=k;i++){
            temp=dist;

            for(int j=0;j<flights.size();j++){
                int u=flights[j][0];
                int v=flights[j][1];
                int w=flights[j][2];

                if(dist[u]==-1)continue;

                if(temp[v]==-1 ||dist[u]+w<temp[v])temp[v]=dist[u]+w;

            }
            dist=temp;
        }
       

      return dist[dst];

	}
};
	// int INF=1e9;
		// vector<vector<int>> dp(k+2,vector<int>(n,INF));
		// dp[0][src]=0;
		// for(int i=1;i<=k+1;i++){
		// 	dp[i][src]=0;
		// 	for(auto x:flights){
		// 		dp[i][x[1]]=min(dp[i][x[1]],dp[i-1][x[0]]+x[2]);
		// 	}
		// }
		// return dp[k+1][dst]>=INF ? -1:dp[k+1][dst];
        

