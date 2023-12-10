class Solution {
public:
    
bool check(int mid,vector<int> &arr, int d){
    int sum=0,c=1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]+sum>mid){
            c++;
            sum=arr[i];
        }
        else{
            sum+=arr[i];
        }
    }
    return c<=d;
}

    
    int shipWithinDays(vector<int>& arr, int d) {
       
    int sum=0,maxi=INT_MIN,n=arr.size();
 
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
        sum+=arr[i];
    }

    int s=maxi,e=sum;
    while(s<=e){

        int mid=s+(e-s)/2;
        if(check(mid,arr,d))e=mid-1;
        else s=mid+1;
    }
    return s;
    }
   
};