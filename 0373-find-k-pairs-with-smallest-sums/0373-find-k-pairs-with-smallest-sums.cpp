
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum=nums1[i]+nums2[j];
                
                if(pq.size()<k)pq.push({sum,{nums1[i],nums2[j]}});       //pushing 1st k elememts in max heap
                else if(sum<pq.top().first)                              //if sum is found kess that top value of pq,                                                                           then pop and add next
                {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else break;  //here arrays are sorted so stop traversing second array when sum is greater than pq.top().first because any way all the elements will be greater after that and it will be of no use
//time will come down to 100ms . so add a break statement in else as shown below
            }
            
        }
        vector<vector<int>> ans;                                            //push values in vector untill heap gets                                                                                       empty and pop in each step
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};


