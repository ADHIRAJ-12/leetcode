class Solution {
public:
    bool checkValidString(string s) {
        
        //simply check at the end of string if the following conditions are fulfilled for open brackets

        int minOpen = 0, maxOpen = 0; // count of minimum open brackets and maximum open brackets
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') { // increasing count for open brackets
                minOpen++;
                maxOpen++;
            } else if(s[i] == ')') { // decreasing count for closed brackets
                minOpen--;
                maxOpen--;
            } else { // case for "*" 
                minOpen--; //considering it as a closing bracket, therefore decreasing the open count
                maxOpen++; //considering it as a opening bracket, therefore increasing the open count
            }
            if(maxOpen < 0) { // opening bracket count decreased to negative, not a valid string because it cant be balanced by '*' as well.
                return false;
            }
            minOpen = max(minOpen, 0); // keeping the case in mind that '*' can be ignored too.
        }
        return minOpen == 0;
    }
};