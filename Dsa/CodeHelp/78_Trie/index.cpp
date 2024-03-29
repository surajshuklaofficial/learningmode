#include <iostream>
using namespace std;

class TrieNode {
    public: 
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    public: 
    TrieNode *root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word){
        // base case 
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption, word will be in CAPS
        int index = word[0] - 'A';

        // present
        if (root->children[index] != NULL) {
            insertUtil(root->children[index], word.substr(1));
            return;
        }

        // absent;
        root->children[index] = new TrieNode(word[0]);
        insertUtil(root->children[index], word.substr(1));
        return;
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }
};

int main() {
    
    Trie *t = new Trie();
    t->insert("SURAJ");
    t->insert("SU");
    t->insert("SURA");

    cout << t->search("SU");
    return 0;
}