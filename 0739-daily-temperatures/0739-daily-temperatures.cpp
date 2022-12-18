class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // vector<int>ans(n,0);
        // for(int i=0;i<n;i++){
        //     int ind=0;
        //      for(int j=i+1;j<n;j++){
        //          if(temperatures[j]>temperatures[i]){
        //         ans[i]=j-i;
        //          break;
        //        }
        //      }
        // }
        // return ans;
  
        int n=temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int,int>> s;
        
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top().first<temperatures[i]){
                auto it=s.top();
                ans[it.second]=i-it.second;
                s.pop();
            }
            s.push({temperatures[i], i});
        }

        return ans;
        
    }
};