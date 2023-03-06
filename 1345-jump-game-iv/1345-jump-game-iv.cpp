class Solution {
public:
    
    int bfs(int node,vector<int>& arr,unordered_map<int,vector<int>> &mp,int n){
        
        vector<bool>visited(n,false);
        queue<int>q;
        int ans=0;
        
        q.push(node);
        visited[node]=true;
        
        while(!q.empty()){
            
            int s=q.size();
            while(s--){
                int index=q.front();
                q.pop();
                visited[index]=true;
                
                if(index==n-1)return ans;
                
                int value=arr[index];
                for(auto &j: mp[value]){
                    
                    if(index==j || visited[j])continue;
                    
                    q.push(j);
                }
                mp[value].clear();
                
                if (index - 1 >= 0 && !visited[index - 1])
                    q.push(index - 1);

                if (index + 1 < n && !visited[index + 1])
                    q.push(index + 1);
            }
            
            ans++;
        }
    
        
        return -1;        
        
    }
    
    int minJumps(vector<int>& arr) {
        
        int n=arr.size();
        if(n==1)return 0;
        if(arr[0]==arr[n-1])return 1;
        
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)  mp[arr[i]].push_back(i);
        
        return bfs(0,arr,mp,n);
        
    }
};