class Solution {
public:
    int strStr(string haystack, string needle) {
        int Cnt = 0;
        int pos = -1;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                pos = i;
                Cnt++;
                for (int j = 1; j < needle.size(); j++) {
                    if (haystack[i + j] == needle[j]) Cnt++;
                    else { 
                        Cnt = 0; 
                        pos = -1; 
                        break; 
                    }
                }
            }
            if (Cnt == needle.size()) break;
        }
        return pos;
    }
};

