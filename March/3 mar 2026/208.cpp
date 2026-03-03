class Trie {
public:
    struct trieNode { 
        trieNode *children[26]; 
        bool isEndOfWord; 
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        
        for (int i = 0; i < 26; i++) {
			newNode->children[i] = NULL;
		}
        
        return newNode;
    }
    trieNode* root;
    
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                crawler->children[index] = getNode();
            
            crawler = crawler->children[index]; 
        }
        
        crawler->isEndOfWord = true; 
    }
    
    bool search(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                return false; 
            crawler = crawler->children[index]; 
        }
        return (crawler != NULL && crawler->isEndOfWord); 
    }
    
    bool startsWith(string prefix) {
        trieNode *crawler = root;
        int i = 0;
        for (i = 0; i < prefix.length(); i++) { 
            int index = prefix[i] - 'a'; 
            
            if (!crawler->children[index]) 
                return false; 
            
            crawler = crawler->children[index]; 
        }
        if(i==prefix.length())
            return true;
        return false;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */