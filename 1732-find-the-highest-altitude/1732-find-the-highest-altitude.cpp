class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n=gain.size();
        int sum=0;
        vector<int>temp;
        temp.push_back(0);
        for(auto i:gain){
            sum+=i;
            temp.push_back(sum);
                        }
      return *max_element(temp.begin(), temp.end());
        
    }
};