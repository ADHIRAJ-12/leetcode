class Solution {
public:
    
    static bool cmp(string &s1, string &s2){
        return (s1+s2)>=(s2+s1);
    }
    
    string largestNumber(vector<int>& nums) {
        
        int zeroes=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)zeroes++;
        }
        
        if(zeroes==n)return "0";
        
        vector<string>temp(n,"");
        
        for(int i=0;i<n;i++)temp[i]=to_string(nums[i]);
        
        sort(temp.begin(),temp.end(),cmp);
        string res="";
        for(int i=0;i<n;i++)res+=temp[i];
        
        return res;
        
    }
};