class Solution {
public:    
    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        stack<int>s1,s2;
        
        //vectors for storing prev and smaller elements
        vector<long long>next_smaller(n),prev_smaller(n);
         
         //base case -if no prev smaller or next smaller exists
        for(int i=0;i<n;i++){
         
         next_smaller[i]=n-i-1;
         prev_smaller[i]=i;

        }
        

        //calculating next smaller
        for(int i=0;i<n;i++){
            while(!s1.empty()&& arr[s1.top()]>arr[i]){
                next_smaller[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
          for(int i=n-1;i>=0;i--){
            while(!s2.empty()&& arr[s2.top()]>=arr[i]){
            prev_smaller[s2.top()]=s2.top()-i-1;
            s2.pop();
            }
            s2.push(i);
        }


        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            ans+=(arr[i]*((prev_smaller[i]+1)%mod)*((next_smaller[i]+1)%mod)%mod);
            ans%=mod;
        }
        return ans;
      
    }
};
