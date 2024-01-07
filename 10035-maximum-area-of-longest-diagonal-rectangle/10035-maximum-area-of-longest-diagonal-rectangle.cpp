class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        int ans=-1,maxi=-1,diag=0,area=0;
        for(auto i:dim){
            diag= i[0]*i[0] + i[1]*i[1];
            area= i[0]*i[1];
            if(diag>maxi){
                maxi= i[0]*i[0] + i[1]*i[1];
                ans=area;
            }
            else if(diag==maxi)ans=max(ans,area);
        }
        return ans;
        
    }
};

       