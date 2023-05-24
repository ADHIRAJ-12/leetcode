class Solution {
public:
    int minLength(string s) {
       stack<int> st;
    for(auto c: s){
        if(c == 'B' && st.size() && st.top() == 'A') st.pop();
        else if(c == 'D' && st.size() && st.top() == 'C') st.pop();
        else st.push(c);
    }
    return st.size();
    }
};