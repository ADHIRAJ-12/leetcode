class Solution {
public:
    bool isValid(string s) {
        
            //UNORDERED MAPS APPROACH
        unordered_map<char,int>m={{'[',-1},{'(',-2},{'{',-3},
                                  {']',1},{')',2},{'}',3}};
        stack<char>st;
        for(char str:s){
            if(m[str]<0)st.push(str);
            else{
                if(st.empty())return false;
                char top=st.top();
                st.pop();
                if(m[top]+m[str]!=0)return false;
            }
        }
        
       if(st.empty())return true;
        return false;
        
        
    }
};
 
        //LOOPING APPROACH

      //taking stack for keep tracking the order of the brackets..
        //as stack works on FILO principle
        
//         stack <char> st;
        
//         int len = s.length();
//         for (int i = 0; i<len ; i++)         //iterate over each and every elements
//         {
//              //if current element of the string will be opening bracket
//              //then we will just simply push it into the stack
            
//             if(s[i] == '(' || s[i] == '{' || s[i] == '[')
//                 st.push(s[i]);
            
//             else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
//             {
//                 if(st.empty())
//                     return false;
                
//                 else if(s[i] == ')' && st.top() != '(')
//                     return false;
                
//                 else if(s[i] == '}' && st.top() != '{')
//                     return false;
                
//                 else if(s[i] == ']' && st.top() != '[')
//                     return false;
                
//                 //if control reaches to that line,
//                 //it means we have got the right pair of brackets,
//                 //so just pop it.
                
//                 else 
//                     st.pop();
//             }
//         }
        
//         if(st.empty())
//             return true;
//         else
//             return false;