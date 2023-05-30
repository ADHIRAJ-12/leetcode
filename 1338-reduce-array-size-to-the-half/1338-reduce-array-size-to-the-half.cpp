class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n=arr.size();
        priority_queue<int>pq;
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++)mp[arr[i]]++;
        int siz=0,sum=0;
        
        for(auto i:mp){
            pq.push(i.second);
            sum+=(i.second);
        }
        
        
        while(sum>n/2){
            siz++;
            sum-=pq.top();
            pq.pop();
        }
        return siz;
        
       
        
    }
};