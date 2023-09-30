class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        vector<int>mini(nums.size()+1);       //min value on left of an element        
        mini[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            mini[i]=min(nums[i],mini[i-1]);
        }
                
        stack<int>s; //for nums[j]
        
        for(int j=nums.size()-1;j>=0;j--){
            if(nums[j]>mini[j] ){
                while(!s.empty()&& s.top()<=mini[j])s.pop();
                if(!s.empty()&& s.top()<nums[j])return true;
                s.push(nums[j]);
            }
            
        }
        return false;
        
    }
};