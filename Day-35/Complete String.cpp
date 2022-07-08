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
    void setEnd() {
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

    bool checkAllPrefixExists(string word) {
        bool flag = true;
        Node *node = root;
        for(int i=0;i<word.size();i++) {
            if(node->containsKey(word[i])) {
                node = node->getNext(word[i]);
                if(!node->isEnd()) return false;
            }
            else return false;
        }
        return true;
    }
    
};
// T.C = O(N) * O(len)
// S.C = We cannot really predict; it is 26x26x26x26x.....
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trieObj;
    for(auto x: a) {
        trieObj.insert(x);
    }
    string longest = "";
    for(auto x:a) {
        if(trieObj.checkAllPrefixExists(x)) {
            if(x.size() > longest.size()) {
                longest = x;
            }
            // if their length are equal then we need to 
            // return the lexicographically smallest one
            else if(x.size()==longest.size() && x < longest) {
                longest = x;
            }
            
            else {
                // longest will remain as it is.
            }
        }
    }
    
    if(longest=="") return "None";
    return longest;
}