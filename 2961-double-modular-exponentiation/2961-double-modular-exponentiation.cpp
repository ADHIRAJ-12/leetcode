class Solution {
public:    
    
    vector<int> getGoodIndices(vector<vector<int>>& arr, int target) {
        
            vector<int>ans;
            for( int i=0;i<arr.size();i++){
            int a=arr[i][0],b=arr[i][1],c=arr[i][2],d=arr[i][3];
                int e=a;
                for(int ii=1;ii<b;ii++)e=(e*a)%10;
                e%=10;
                int ee=e;
                for(int ii=1;ii<c;ii++)ee=(ee*e)%d;
                ee%=d;
                if((ee%d)==target)ans.push_back(i);
            }
        return ans;
        
    }
};