class Solution {
public:
    bool halvesAreAlike(string s) {
        
//         int n=s.size();

//     string p=s.substr(0,n/2);
//     string q=s.substr(n/2+1,n);

//     int count1=0,count2=0;
    

//     for(int i=0;i<p.size();i++){
//       if(p[i]=='a'||p[i]=='e'||p[i]=='i'||p[i]=='o'||p[i]=='u'||p[i]=='A'||p[i]=='E'||p[i]=='I'||p[i]=='O'||p[i]=='U')count1++;
//     }
//       for(int i=0;i<q.size();i++){
//       if(q[i]=='a'||q[i]=='e'||q[i]=='i'||q[i]=='o'||q[i]=='u'||q[i]=='A'||q[i]=='E'||q[i]=='I'||q[i]=='O'||q[i]=='U')count2++;
//     }


//  return (count1==count2);


        int n=s.size();
        int a=0,b=0;
        vector<char>vowels={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0;i<n/2;i++){
            for(auto x : vowels){
                if(s[i]==x){
                    a++;
                    break;
                }
            }
        }
        for(int i=n/2;i<n;i++){
            for(auto x : vowels){
                if(s[i]==x){
                    b++;
                    break;
                }
            }
        }
        return a==b;    
    }
};