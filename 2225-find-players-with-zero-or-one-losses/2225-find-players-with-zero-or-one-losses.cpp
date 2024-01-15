class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
    // creat a a map/array  for number of losses,return  the elemnts having one or 0 losses
  
   map<int,int>m;
   vector<vector<int>>res(2);

   for(auto it:matches){
       m[it[0]]=m[it[0]];
       m[it[1]]=m[it[1]]+1;
   }

  

      for(auto it:m){
       if(it.second==0)res[0].push_back(it.first);

       else if(it.second==1)res[1].push_back(it.first);
   }

    return res;
    }
};