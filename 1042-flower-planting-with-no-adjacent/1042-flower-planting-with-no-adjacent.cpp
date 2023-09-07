class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<int>adj[n+1];
        vector<int>color(n+1,0);
        
        for(auto i:paths){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                color[i]=1;
                queue<int>q;
                q.push(i);
                
                while(!q.empty()){
                    int top=q.front();
                    q.pop();
                    
                    for(auto nbr:adj[top]){
                        if(color[nbr]==0){
                            color[nbr]=color[top]+1;
                            q.push(nbr);
                        }
                        else if(color[top]==color[nbr])color[nbr]= (color[top]+1);
                        
                        if(color[nbr]==5)color[nbr]=1;   
                    }
                }
            }
        }
        color.erase(color.begin());
        return color;
    }
};