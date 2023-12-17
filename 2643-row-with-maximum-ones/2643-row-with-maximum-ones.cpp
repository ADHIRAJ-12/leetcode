class Solution {
public:
    
    int lowerBound(vector<int> arr, int n, int x) {

	int ans=n;

	int s=0,e=n-1;
	while(s<=e){

		int mid=s+(e-s)/2;
		if(arr[mid]>=x){
			ans=mid;
			e=mid-1;
		}
		else s=mid+1;

	}
	return ans;
}

    
    vector<int> rowAndMaximumOnes(vector<vector<int>>& matrix) {
         for(auto &row:matrix){
            sort(row.begin(), row.end());
        }
    int count=0,index=0,n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
       int ones=m-lowerBound(matrix[i],m,1);
        if(ones>count){
            count=ones;
            index=i;
        }
    }
         return {index,count};
    }
};