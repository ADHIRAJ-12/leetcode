class Solution {
public:
    
    long long trips(long long sec,vector<int> &time){
        long long n=time.size();
        long long count=0;
        for(int i=0;i<n;i++) count+=(sec/time[i]);
        return count;
    }
    
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long s=0,e=1e14;
        long long ans=e;
        
        while(s<=e){
            
            long long mid=s+(e-s)/2;
            if(trips(mid,time)>=totalTrips){
                ans=mid;
                e=mid-1;
            }
            
            else s=mid+1;
            
        }
        return ans;
        
    }
};