class Solution {
public:
    double average(vector<int>& salary) {
        
        int n=salary.size();
        sort(salary.begin(),salary.end());
        double ans;
        for(int i=1;i<n-1;i++)ans+=salary[i];
        cout<<ans;
        return ans/double(n-2);
        
    }
};