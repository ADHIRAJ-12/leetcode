class Solution {
public:
    
    bool solve(int mid,vector<int>& piles, int h){
        
        long count=0;
        for(int i=0;i<piles.size();i++){
            int div=piles[i]/mid;
            count+=div;
            if(piles[i]%mid !=0)count++;
        }
        return count<=h;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
            
        int s=1,e=1000000000;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(solve(mid,piles,h))e=mid-1;
            else s=mid+1;
        }
        return s;
    }
};