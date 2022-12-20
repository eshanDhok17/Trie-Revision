// L4 - Count Distint Substrings

#include<bits/stdc++.h>
class Node {
    public:
    Node* links[26];
    Node* get(char ch) {
        return links[ch-'a'];
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    bool containsKey(char ch) {
       return links[ch-'a']; 
    }
};

class Trie {
    private:
    Node *root;
    public:
    int cnt = 1;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        auto node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
                cnt++;
            }
            node = node->get(word[i]);
        }
    }
};
int countDistinctSubstrings(string &s) {
    Trie trie;
    int n = s.size();
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            trie.insert(s.substr(i, j-i+1));
        }
    }
    return trie.cnt;
}