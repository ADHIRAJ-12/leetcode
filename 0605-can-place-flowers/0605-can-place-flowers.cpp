class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int m=arr.size();
        int count=0;
        for(int i=0;i<m;i++){
        if(arr[i] == 0 && (i == 0 || arr[i-1] == 0) && (i == m-1 || arr[i+1] == 0)){
                arr[i]=1;
                count++;
            }
            if (count >= n) return true;
            
        }
        return false;
    }
};