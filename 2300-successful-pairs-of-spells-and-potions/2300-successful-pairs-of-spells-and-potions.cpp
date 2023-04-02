class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int>ans(n,0);
        sort(potions.begin(),potions.end());
        
        for(int i=0;i<n;i++){
            
            int s=0,e=m-1;
            int temp=spells[i];
            while(s<=e){
                int mid=s+(e-s)/2;
                long long prod=(long long )temp*potions[mid];
                if(prod>=success)e=mid-1;
                else s=mid+1;
            }
          ans[i]=m-s;  
        }
        return ans;
    }
};