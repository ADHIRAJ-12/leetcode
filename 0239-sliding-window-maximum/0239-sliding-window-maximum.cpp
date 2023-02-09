class Solution {
    private:
    vector<int>  solve(vector<int>& nums, int n, int k) {

    deque<int> maxi(k);
        vector<int>sol;
   
    // first k size window

    for(int i=0; i<k; i++) {

        while(!maxi.empty() && nums[maxi.back()] <= nums[i])
            maxi.pop_back();


        maxi.push_back(i);
      
    }
        
    int ans = 0;

    ans = nums[maxi.front()] ;
         sol.push_back(ans);

    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {

        

        //next window

        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }

      
        //addition

        while(!maxi.empty() && nums[maxi.back()] <= nums[i])
            maxi.pop_back();

        

        maxi.push_back(i);
       

        ans = nums[maxi.front()];
      sol.push_back(ans);
    }
          
    return sol;
        
}

        
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      
     int n=nums.size();
        return  solve(nums,n,k);
        
        
    }
};