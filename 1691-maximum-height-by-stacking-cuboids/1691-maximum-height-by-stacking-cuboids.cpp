class Solution {
public:
    
    bool check(vector<int>base,vector<int> newBox){
        if(newBox[0]<=base[0] &&newBox[1]<=base[1] &&newBox[2]<=base[2] )
        return true;
         
        else return false;
        
        
    }
  int solveSpace(int n,vector<vector<int>>& nums){
      
      vector<int>currRow(n+1,0);
      vector<int>nextRow(n+1,0);  

        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                
                
                 int include=0;
        if(prev==-1 || check( nums[curr],nums[prev])) 
            include=nums[curr][2]+nextRow[curr+1];
        
        int exclude=0+nextRow[prev+1];
        
        currRow[prev+1] =max(include,exclude);
                
            }
            nextRow=currRow;
        }
        

        return nextRow[0];
    }
    
    
    int maxHeight(vector<vector<int>>& cuboids) {
        
    //sort all dimensions of every cuboid
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
        }
        
        //sort on basis of width or length
        sort(cuboids.begin(),cuboids.end());
        
        //lis ques logic
        return solveSpace(cuboids.size(),cuboids);
        
    }
};