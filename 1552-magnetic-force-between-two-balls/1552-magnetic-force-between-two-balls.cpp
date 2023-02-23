class Solution {
public:
    
    
    bool solve(vector<int> &position,int mid,int m,int n){
        
        int prev=position[0];
        int requiredBalls=1;
        for(int i=1;i<n;i++){
            if(position[i]-prev>=mid){
                prev=position[i];
                requiredBalls++;
            }
        }
        
        if(requiredBalls>=m)return true;
        return false;
    }
        
        
    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(),position.end());
        int n=position.size(),s=1,e=position[n-1],mid,res=-1;
        
        while(s<=e){
            mid=s+(e-s)/2;
            if(solve(position,mid,m,n)){
                res=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        return res;
    }
};