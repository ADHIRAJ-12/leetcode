class Solution {
public:
    
    bool solve(long long  mid,vector<int>& candies,long long k){
        
        long long  count=0;
        for(auto candy:candies){
            count+=candy/mid;
            if(count>k)return true;
        }
        return count>=k;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        
       long long start=1,end=1e12;
        long long  ans=0;
        while(start<=end){
            
            long long  mid=start+(end-start)/2;
            if(solve(mid,candies,k)){
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans;
        
    }
};