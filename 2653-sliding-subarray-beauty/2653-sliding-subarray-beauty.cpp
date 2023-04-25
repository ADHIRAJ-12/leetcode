class Solution {
public:
 
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        //there are only 51 negative numbers so we have to keep the track of count of these
        vector<int>freq(51,0),ans;
        for(int i=0,j=0;i<n;i++){
            //store freq of negativr element
        if(nums[i]<0)freq[abs(nums[i])]++;
        ///window check
        if(i-j+1>=k){
            int count=0;
            for(int a=50;a>=1;a--){
            //finding xth smallest number
                count+=freq[a];
                if(count>=x){
                    //if found ,store ans & break
                    ans.push_back(-a);
                    break;
                }
            }
        //if no number found
            if(count<x)ans.push_back(0);
            if(nums[j] <0) freq[abs(nums[j])]--;
            j++;
          }
        }
        return ans;
        
    }
};