class Solution {
public:
    
    bool safe(int row,int col,vector<string>&board,int n){
        int roww=row,coll=col;
        
        //diag to upper left 
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }        
        row=roww;
        col=coll;
        
        //diag to lower left
        while(row<n && col>=0){
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }        
        row=roww;
        col=coll;
        
        //same row
        while( col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }        
        
        return true;        
    }
    
    
    void f(int col,int n,vector<string>&board,vector<vector<string>>&ans){
        
        //base
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(safe(row,col,board,n)){
                board[row][col]='Q';
                f(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        f(0,n,board,ans);
        
        return ans;
    }
};

//vector<string>board(n);
//string s(n,".");
//for(int i=0;i<n;i++)board[i]=s;