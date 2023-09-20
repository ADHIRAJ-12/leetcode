class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int duplicate = -1;
    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            duplicate = nums[i];
            break;
        }
    }
    return duplicate;

        
    }
};



// int findDuplicate(vector<int>& nums) {
//          int n = nums.size();

//     for (int i = 0; i < n; i++)
//         for (int j = i + 1; j < n; j++)
//             if ((nums[i] ^ nums[j]) == 0)
//                 return nums[i];
//     return -1;