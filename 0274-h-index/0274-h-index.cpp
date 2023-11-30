class Solution {
public:
    int hIndex(vector<int>& arr) {
        int s=0,n=arr.size(),e=n-1, mid=s+(e-s)/2;
        sort(arr.begin(),arr.end());
    while(s<=e){
     
        if(arr[mid]>= n-mid) e=mid-1;
        else s=mid+1;

        mid=s+(e-s)/2;
    }
      return n-s;
    
    }
};