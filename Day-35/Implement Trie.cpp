/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node {
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch) {
        return links[ch-'a'];
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* getNext(char ch) {
        return links[ch - 'a'];
    }
    bool setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};
class Trie {
private: Node *root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    // T.C = O(len)
    void insert(string word) {
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
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->getNext(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0;i<prefix.length();i++) {
            if(!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->getNext(prefix[i]);
        }
        return true;
    }
};