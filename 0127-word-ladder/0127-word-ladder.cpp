class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>>q;
        set<string>st(wordList.begin(),wordList.end());
        
        q.push({beginWord,1});    //starting word with level =1
        st.erase(beginWord);     //marking visited
        
        
        //bfs
        
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            
            if(word==endWord)return step;
            
            for(int i=0;i<word.length();i++){
                char current=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=current;
            }
            
            
        }
        return 0;
        
        
    }
};