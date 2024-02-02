class Solution {
public:
    
    void solve(int curr_num,int next_num,vector<int>&ans,int low,int high){
        
        while(curr_num<=high && next_num<=9){
                
              curr_num=curr_num*10+next_num;      //12,123,1234,12345........23,234,2345....
              if(curr_num>=low && curr_num<=high)ans.push_back(curr_num);  //belong to range
              next_num++;                //3
            }
    }
    
    
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int>ans;
        
        for(int i=1;i<=9;i++){
            
            int curr_num=i;            //1,2,3,4,5.....
            int next_num=i+1;          //2,3,4,5,6......
            solve(curr_num,next_num,ans,low,high);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};