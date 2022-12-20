class Solution {
public:
     void dfs(int ind,vector<bool> &visited,vector<vector<int>>& rooms){
       
         visited[ind]=true;
         for(int i=0;i<rooms[ind].size();i++){
             if(!visited[rooms[ind][i]])dfs(rooms[ind][i],visited,rooms);
         }
     }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        
       vector<bool>visited(n,false);
       dfs(0,visited,rooms);
        for(int i=0;i<n;i++){
            if(!visited[i])return false;
        }
        return true;
    }
};