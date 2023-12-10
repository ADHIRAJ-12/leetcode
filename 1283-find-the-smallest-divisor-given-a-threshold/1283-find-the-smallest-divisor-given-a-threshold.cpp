class Solution {
public:
    
    bool check(int mid,vector<int>& arr, int limit){

	int sum=0;
	for(int i=0;i<arr.size();i++){
		sum=sum+ceil(double(arr[i])/double(mid));
	}
return sum<=limit;

}

    
    int smallestDivisor(vector<int>& arr, int limit) {
        
        int n=arr.size();
	int maxi=INT_MIN;

	for(int i=0;i<n;i++){
		// mini=min(mini,arr[i]);
		maxi=max(maxi,arr[i]);
	}

	int s=1,e=maxi;
	while(s<=e){

		int mid=s+(e-s)/2;
        if (check(mid, arr, limit))e = mid - 1;
        else s=mid+1;

	}
	return s; 
        
    }
};