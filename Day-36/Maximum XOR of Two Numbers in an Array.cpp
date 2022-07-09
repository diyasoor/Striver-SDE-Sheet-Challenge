class Node {
public:
    Node* links[2]; // 0 / 1
    bool containsKey(int bit) {
        return links[bit];
    }
    Node* getNext(int bit) {
        return links[bit];
    }
    void put(int bit,Node* node) {
        links[bit] = node;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for(int i=31;i>=0;i--) {
            int bit = (num >> i) & 1; // bit set or not
            if(!node->containsKey(bit)) {
                node->put(bit,new Node());
            }
            node=node->getNext(bit);
        }
    }
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for(int i=31;i>=0;i--) {
            int bit = (num >> i) & 1;
            // check if the opposite bit is present or not
            if(node->containsKey(1 - bit)) {
                maxNum = maxNum | (1 << i); // add it by doing left shift
                node = node->getNext(1 - bit); 
            }
            else {
                node = node->getNext(bit);
            }
        }
        return maxNum;
    }
};
int maximumXor(vector<int> A)
{
    // Write your code here.   
    Trie trie;
    for(auto x:A) trie.insert(x);
    
    int maxXor = 0;
    for(auto x: A) {
        maxXor = max(maxXor, trie.getMax(x)); 
    }
    return maxXor;
}