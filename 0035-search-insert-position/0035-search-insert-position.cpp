class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
     return lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    }
};