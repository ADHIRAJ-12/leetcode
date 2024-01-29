class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int a=0,b=0;
        unordered_map<int,int>m,n;
        for(int i=0;i<nums1.size();i++)m[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)n[nums2[i]]++;
        
        for(int i=0;i<nums1.size();i++){
            if(n.find(nums1[i])!=n.end())b++;
        }
         for(int i=0;i<nums2.size();i++){
            if(m.find(nums2[i])!=m.end())a++;
        }
        return {b,a};
    }
};