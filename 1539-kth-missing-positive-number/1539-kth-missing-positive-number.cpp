class Solution {
public:
    int findKthPositive(vector<int>& vec, int k) {
    int n=vec.size();
        int s=0,e=n-1;
    while (s<=e){
        
        int mid=s+(e-s)/2;
         int mis=vec[mid]-(mid+1);
        
        if(mis<k)s=mid+1;
        else e=mid-1;
    }
    return s+k;
    }
};

