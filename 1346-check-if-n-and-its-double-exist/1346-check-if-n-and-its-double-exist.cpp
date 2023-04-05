class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
       
         int n=arr.size();
         sort(arr.begin(),arr.end());
     
        for(int i=0;i<n;i++){ 
            int s = 0, e =n-1;
            int target = 2*arr[i];
            while(s<=e){
                int mid = s+(e-s)/2;
                if((arr[mid]==target) && (i!=mid))return true;
                else if(arr[mid] > target){
                    e = mid-1;
                }
                else   
                    s = mid+1;
            }
        }
        return false;
    }
};