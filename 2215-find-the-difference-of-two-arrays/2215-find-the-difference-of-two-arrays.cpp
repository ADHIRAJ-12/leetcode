class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
          
        vector<vector<int>>ans;
        vector<int>temp;
        unordered_map<int,int>np,mp;
        
        int n=nums1.size(),m=nums2.size();
        
        for(int i=0;i<n;i++)np[nums1[i]]++;
        for(int j=0;j<m;j++)mp[nums2[j]]++;
                
        
        for(auto i:np){
            if(mp.find(i.first)==mp.end())temp.push_back(i.first);
        }
        ans.push_back(temp);
        temp.clear();
         for(auto i:mp){
            if(np.find(i.first)==np.end())temp.push_back(i.first);
        }
        ans.push_back(temp);
        
        return ans;
    }
};