class Solution {
public:
 void f(int ind,int c,int k,int t,int n, vector<vector<int>> &res,vector<int> &ans,vector<int>& arr){

        if(t==0 && c==k ){
            res.push_back(ans);
            return;
        }


        for(int i=ind;i<n;i++){
            //leaving same element [1,1,1,2] eg
            // if(i>ind && arr[i]==arr[i-1])continue;

        if(arr[i]>t)break;    
    //sorted aaray so if 3rd ind is >target ,all further index wil be bigger for sure
         ans.push_back(arr[i]);
            c++;
         f(i+1,c,k,t-arr[i],n,res,ans,arr);
         ans.pop_back();
            c--;
        }

}
    
    vector<vector<int>> combinationSum3(int k, int target) {
    
    vector<int>candidates={1,2,3,4,5,6,7,8,9};
     vector<vector<int>>res;
     vector<int> ans;
     int n=candidates.size();
      f(0,0,k,target,9,res,ans,candidates);

      return res;
        
        
    }
};