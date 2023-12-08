class Solution {
public:
    
    
    int f(int mid,vector<int>&arr,int m,int k){
        
        int c=0,total=0;
        for(int i=0;i<arr.size();i++){
                if(arr[i]<=mid)c++;
            else{
                total+=c/k;
                c=0;
            }
        
        }
        
        total+=c/k;
        return total>=m;
    }
    
    
    
    int minDays(vector<int>& arr, int m, int k) {
        
        
         long long val=k*1LL*m*1LL;
         if(val>arr.size())return -1;
        
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        for(int i=0;i<arr.size();i++){
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
        }
        
        
        int s=mini,e=maxi;
        while(s<=e){
            
        int mid=s+(e-s)/2;
        
        if(f(mid,arr,m,k))e=mid-1;
        else s=mid+1;
            
        }
        
        return s;
        
    }
};