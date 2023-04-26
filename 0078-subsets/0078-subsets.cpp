class Solution {

// void solve( vector<vector<int>> &ans,vector<int> &temp,vector<int>& nums,int index){
    
//     int n=nums.size();
//     if(index==n){
//         ans.push_back(temp);
//         return;
//     }
    
//     //include
//     temp.push_back(nums[index]);
//     solve(ans,temp,nums,index+1);
//     temp.pop_back();
    
//     //exlude
//     solve(ans,temp,nums,index+1);
    
// }
    
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // vector<vector<int>> ans;
        // vector<int>temp;
        // solve(ans,temp,nums,0);
        // return ans;
        
        //bitmasking solution 
        int n=nums.size();
        int count=1<<n;
        vector<vector<int>>ans;
        for(int mask=0;mask<count;mask++){
        vector<int>temp;
        for(int i=0;i<n;i++){
            if((mask & (1<<i))!=0){
                temp.push_back(nums[i]);
            }
        }
            ans.push_back(temp);
     }  
        return ans;
            
    }
};

        
        
        

        // vector<vector<int>>ans;
       //  vector<int>output;
       //  int index=0;
       //  solve(nums,output,index,ans);
       //  return ans;
        //     private:
    
//     void solve(vector<int> nums,vector<int>output,int index,vector<vector<int>>& ans){
//         if(index>=nums.size()){
//             ans.push_back(output);
//             return;
//         }
//          solve(nums,output,index+1,ans); 
        
//         int element=nums[index];
//         output.push_back(element);
//         sort(output.begin(),output.end());

//          solve(nums,output,index+1,ans);
//     }
        