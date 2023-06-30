class Solution {
public:
    
    
    void dfs(int i,int j,vector<vector<char>>& nums){
        
        int n=nums.size();
        int m=nums[0].size();
        if(i>=0 && j>=0 && i<n && j<m && nums[i][j]=='X'){
            nums[i][j]='.';
            dfs(i+1,j,nums);
            dfs(i,j+1,nums);
            dfs(i-1,j,nums);
            dfs(i,j-1,nums);
        }
        
        
    }
    
    
    
    int countBattleships(vector<vector<char>>& nums) {
        
        int n=nums.size();
        int m=nums[0].size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]=='X'){
                    c++;
                    dfs(i,j,nums);
                }
            }
        }
        return c;
    }
};