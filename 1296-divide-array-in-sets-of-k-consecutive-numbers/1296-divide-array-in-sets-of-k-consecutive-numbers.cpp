class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(n%k!=0)return false;
        
        
        sort(nums.begin(),nums.end());
        unordered_map<int,int>count;
        
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        
        
        for(int i=0;i<n;i++){
            
            if(count[nums[i]]==0)continue;
            
            count[nums[i]]--;
            
            for(int j=1;j<k;j++){
                
                if(count[nums[i]+j]==0)return false;
                
                count[nums[i]+j]--;
            }
            
            
            
        }
        
        return true;
    }
};