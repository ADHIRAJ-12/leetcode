
    /*n=numRows
Δ=2n-2    1                           2n-1                         4n-3
Δ=        2                     2n-2  2n                    4n-4   4n-2
Δ=        3               2n-3        2n+1              4n-5       .
Δ=        .           .               .               .            .
Δ=        .       n+2                 .           3n               .
Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
Δ=2n-2    n                           3n-2                         5n-4
*/
    
    

class Solution {
public:
    
    string convert(string s, int rows) {
        
        string ans="";
        vector<string>temp(rows,"");
        int i=0;
        int n=s.size();
        
        while(i<n){
            
            // phli loop 0 to rows-1 tak store karegi
            for(int j=0;j<rows && i<n;j++){
                temp[j].push_back(s[i]);
                i++;
            }
            
            //2nd loop rows-2 se upr ki trf chlegi jabtak 1st char se 1 neche ki length par na phuch jaye
            
            for(int j=rows-2;j>=1 && i<n;j--){
                 temp[j].push_back(s[i]);
                i++;
            }
            
        }
        
        for(auto i:temp){
            ans+=i;
        }
        return ans;
        
    }
};

