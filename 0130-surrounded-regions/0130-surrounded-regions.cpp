class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0|| j==0||i==n-1||j==m-1 )&& board[i][j]=='O'){
                    q.push({i,j});
                }
            }
        }
        
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            board[row][col] = '#';
            
            for(int i=0;i<4;i++){
                    int nrow=row+dx[i];
                    int ncol=col+dy[i];
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O')q.push({nrow,ncol});
                
            }
            
        }
        
        
           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='#')board[i][j]='O';
                
            }
        }
        
        
        
        
    }
};