class Solution {
public:
    int similarPairs(vector<string>& words) {
        
        
         vector<string>vec;
        int count=0;
        int n=words.size();
        
        for(int i=0;i<n;i++){
            string s=words[i];
            set<char>myset;
            
            for(int j=0;j<s.size();j++){
                myset.insert(s[j]);
            }
            
            string temp;
            for(auto it= myset.begin();it!= myset.end();it++){
                temp.push_back(*it);
            }
            vec.push_back(temp);
        }
        
        for(int i=0;i<vec.size();i++){
            for(int j=i+1;j<vec.size();j++){
                if(vec[i]==vec[j])count++;
            }
        }
        return count;
        
                                            //failed attemp1;
        
        
         // int n=words.size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if((words[i])==(words[j])count++;
//             }
//         }
//             return count;
            
        
                                           //failed attemp 2
        
        
//         int n=words.size();
//         int count=0;
//          for(int i=0;i<n;i++){
//           for(int j=i+1;j<n;j++){
//               if(words[i].size()==words[j].size()){
//                   bool flag=true;
//                    unordered_set<char>s;
//                   for(char c:words[i])s.insert(c);
                  
//                   for(char c:words[j]){
//                       if(s.count(c)==0){
//                           flag=false;
//                           break;
                    
//                      }
//                   }
//                   if(flag)count++;
//                   }
//           }
//         }
//         return count;
      
        
       //  vector<string>vec; 
       //  //for comparing stored values later on and adding to result if found equal
       //   int result= 0; 
       //  //for storing final ans
       //  for(string s :words){
       //      //takeout a string from words
       //      set<char> myset;
       //      //creating a set of chars
       //      s.erase(remove_if(s.begin(),s.end(),[&myset] (char i) {if (myset.count(i)) { 
       //          return true; 
       //      } myset.insert(i);
       //          return false; }),s.end());
       //      //sort this string
       //      sort(s.begin(),s.end());
       //      //  push in vec finally
       //      vec.push_back(s);
       //      }
       // //traverse vec for simiar elements
       //  int siz=vec.size();
       //  for(int i =0;i<siz-1;i++){
       //      for(int j= i+1 ;j<siz;j++){
       //          if(vec[i]==vec[j])result+= 1;  
       //          //if found same increment final ans
       //      }
       //  }
       //  return result;         
        
    }
};