class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        map<pair<int,int>,int>m;
      vector<int>degree(n);
      
      for(int i=0;i<roads.size();i++)
      {
        m[{roads[i][0],roads[i][1]}]=1;
        m[{roads[i][1],roads[i][0]}]=1;
        degree[roads[i][0]]++;
        degree[roads[i][1]]++;
      }
      
      int count=0;
      for(int i=0;i<n;i++)
      {
         for(int j=i+1;j<n;j++)
         {
            if(m[{i,j}]==1 || m[{j,i}]==1)count=max(count,degree[i]+degree[j]-1);
            else count=max(count,degree[i]+degree[j]); 
         }
      }
       
      return count;
        
    }
};