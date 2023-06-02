class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        int res=0;
        
        //sort every row
        for(int i=0;i<n;i++)sort(nums[i].begin(),nums[i].end());
        
        //travese every column
        for(int col=0;col<m;col++){
            int temp=0;
            //travese every row 
             for(int row=0;row<n;row++){
                 
                 //find max in every row
                 temp=max(temp,nums[row][col]);  
             }
            //store max value in result
            res+=temp;
            
        }
        //return result
        return res;
    }
};