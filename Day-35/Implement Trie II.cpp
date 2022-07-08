class Node {
public:
    Node *links[26];
    int cntEndWith=0;
    int cntPrefix=0;
      
    bool containsKey(char ch) {
        return links[ch-'a'];
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* getNext(char ch) {
        return links[ch - 'a'];
    }
    void increaseEndWith() {
        cntEndWith++;
    }
    void increasePrefix() {
        cntPrefix++;
    }
    void decreaseEndWith() {
        cntEndWith--;
    }
    void decreasePrefix() {
        cntPrefix--;
    }
    int getEndWith() {
        return cntEndWith;
    }
    int getPrefix() {
        return cntPrefix;
    }
};
class Trie{
    private: Node* root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *node = root;
        for(int i=0;i<word.size();i++) {
            // if not contains then we'll put it 
            // with a new reference node for further insertion
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            // it will moves to the reference trie, 
            // as it already contains the character
            node = node->getNext(word[i]);
            node->increasePrefix();
        }
        node->increaseEndWith();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node *node = root;
        for(int i=0;i<word.size();i++) {
            if(node->containsKey(word[i])) {
               node = node->getNext(word[i]);
            }
            else return 0;
        }
        return node->getEndWith();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node *node = root;
        for(int i=0;i<word.size();i++) {
            if(node->containsKey(word[i])) {
               node = node->getNext(word[i]);
            }
            else return 0;
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node *node = root;
        for(int i=0;i<word.size();i++) {
            if(node->containsKey(word[i])) {
               node = node->getNext(word[i]);
               node->decreasePrefix();
            }
            else return;
        }
        node->decreaseEndWith();
    }
};
