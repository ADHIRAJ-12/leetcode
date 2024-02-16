class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        int n=nums.size(),c=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)m[nums[i]]++;
        
        vector<int>freq;
        for(auto i:m)freq.push_back(i.second);
        sort(freq.begin(),freq.end());
    
         
            for(int i=0;i<freq.size();i++){
                if(freq[i]>k){
                    freq[i]-=k;
                    k=0;
                }
                else{
                    k-=freq[i];
                    freq[i]=0;
                }
                if(freq[i]!=0)c++;
            }
       
        return c;
        
    }
};