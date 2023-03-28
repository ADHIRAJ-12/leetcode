class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>ans;
        unordered_map<int,int>m,n;
        
        for(int i=0;i<nums1.size();i++)m[nums1[i]]++;
        
        for(int i=0;i<nums2.size();i++){
            if(m.find(nums2[i])!=m.end())n[nums2[i]]++;
        }
        
        for(auto i:n)ans.push_back(i.first);
        return ans;

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         vector<int>ans;
//         sort(nums1.begin(),nums1.end());
//         sort(nums2.begin(),nums2.end());
        
//         int i=0,j=0, n=nums1.size(),m=nums2.size();
        
//         while(i<n && j<m){
//             if(nums1[i]==nums2[j]){
//                 ans.push_back(nums1[i]);
//                 i++;
//                 j++;
//             }
//           else  if(nums1[i]<nums2[j]){
//                 i++;
//             }
//           else  {
//                 j++;
//             }
//         }
//         ans.erase(unique(ans.begin(),ans.end()),ans.end()); 
//         return ans;
    }
};