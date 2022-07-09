class Node {
public:
    Node* links[26];
    bool containsKey(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    Node* getNext(char ch) {
        return links[ch-'a'];
    }
};
class Trie {
private:
    Node *root;
    int cnt=0;
public:
    Trie() {
        root=new Node();
        cnt=0;
    }
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
                cnt++;
            }
            node = node->getNext(word[i]);
        }
    }
    int getDistinctCnt() {
        return cnt;
    }
};
int distinctSubstring(string &word) {
    //  Write your code here.
    Trie trieObj;
    int n = word.size();
    for(int i=0;i<n;i++) {
        trieObj.insert(word.substr(i, n - i));
    }
    return trieObj.getDistinctCnt();
}
