class Solution {
public:
    
//   int getPivot(vector<int>& arr,int n)
// {
// int s=0;
//     int e=n-1;
//     int mid= s+(e-s)/2;
//     while(s<e){
//         if(arr[mid]>=arr[0]){
//             s=mid+1;
//         }
//         else{
//             e=mid;
//         }
//         mid= s+(e-s)/2;
//     }
//     return s;
// }
    
    
// bool binarySearch(vector<int>& arr, int s,int e, int key) {

//     int start = s;
//     int end = e;

//     int mid = start + (end-start)/2;

//     while(start <= end) {

//         if(arr[mid] == key) {
//             return true;
//         }

        
//         if(key > arr[mid]) {
//             start = mid + 1;
//         }
//         else{ 
//             end = mid - 1;
//         }

//         mid = start + (end-start)/2;
//     }
    
//     return false;
// }
    
    
    bool search(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     int pivot=getPivot(nums,n);
    //     if (target>=nums[pivot]&&target<=nums[n-1]){
    //     return binarySearch(nums,pivot,n-1,target);
    // }
    // else{
    //     return binarySearch(nums,0,pivot-1,target);
    // }
       
        sort(nums.begin(),nums.end());
        int n=nums.size();
            
        int s=0,e=n-1;
        int mid=s+(e-s)/2;
        
        while(s<=e){
            if(nums[mid]==target)return true;
            
            else if(target>nums[mid]) {s=mid+1;}
            
            else {e=mid-1;}
            
             mid=s+(e-s)/2;

        }
        return false;
    }
};








//         //linear search
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==target) return true;
//         }
//         return false;
        
        //binary search
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
            
//         int s=0,e=n-1;
//         int mid=s+(e-s)/2;
        
//         while(s<=e){
//             if(nums[mid]==target)return true;
            
//             else if(target>nums[mid]) {s=mid+1;}
            
//             else {e=mid-1;}
            
//              mid=s+(e-s)/2;

//         }
//         return false;