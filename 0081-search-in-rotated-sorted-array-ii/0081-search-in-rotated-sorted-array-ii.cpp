class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int n=arr.size();
    int s=0,e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==k)return true;
        if(arr[s]==arr[mid] && arr[mid]==arr[e]){
            s++;
            e--;
            continue;
        }

            //left part sorted
        if(arr[s]<=arr[mid]){

                if(arr[s]<=k && arr[mid]>=k )e=mid-1;
                else s=mid+1;

        }
        //right part sorted
        else{

            if(arr[mid]<=k && arr[e]>=k)s=mid+1;
            else e=mid-1;

        }


    }
return false;
    }
};