// Complete String

#include <bits/stdc++.h> 
class Node {
    public:
    Node* links[26];
    bool fg = false;
    Node* get(char &ch) {
        return links[ch - 'a'];
    }
    void put(char &ch, Node* node) {
        links[ch - 'a'] = node;
    }
    bool containsKey(char &ch) {
        return links[ch - 'a'];
    }
    bool isEnd() {
        return fg;
    }
    void setEnd() {
        fg = true;
    }
};
class Trie {
    private:
    Node* root;
    public:
    Trie() {
        root = new Node();
    }
    void insert(string &word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool containsPrefix(string &word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
                if(node->isEnd() == false) return false;
            }
            else return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto it : a) {
        trie.insert(it);
    }
    string res = "";
    for(auto &it : a) {
        if(trie.containsPrefix(it)) {
            if(it.size() > res.size()) {
                res = it;
            }
            else if(it.size() == res.size() and it < res) {
                res = it;
            } 
        }
    }
    return res == "" ? "None" : res;
}