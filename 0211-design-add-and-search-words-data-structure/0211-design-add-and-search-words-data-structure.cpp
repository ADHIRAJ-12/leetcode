  struct Node{

        Node *links[26];
        bool flag=false;

        bool contains(char ch){
            return (links[ch-'a']!=NULL);
             }

        void put(char ch,Node *node){
            links[ch-'a']=node;
        }

Node *get(char ch) {
		return links[ch - 'a'];
	}
	void setEnd() {
		flag = true;
	}
	bool isEnd() {
		return flag;
	}
    
};

class WordDictionary {
    private: Node* root;
public:
    
    WordDictionary() {
         root=new Node();
    }
    
    void addWord(string word) {
         Node *node=root;
        for(int i=0;i<word.length();i++){
            if(!node->contains(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node=root;
        return f(word,node,0);
    }
    
    
    bool f(string &word, Node *node, int ind){
        if(node == NULL)
            return 0;
        if(ind == word.size())
            return node->isEnd();

        if(word[ind] != '.')
            return f(word, node->get(word[ind]), ind+1);

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(f(word, node->get(ch), ind+1))return true;
        }

        return false;
    }
    
    
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */