#ifndef _TRIE_TREE_H_
#define _TRIE_TREE_H_

#include <vector>
#include <string>
using namespace std;

class TrieTree
{
private:
    static const int ALPHABET_SIZE = 256; // the cardinality of alpbabet set

    // the trie-tree-node definition
    struct TrieNode
    {
        int cntPrefix; // occurance of prefix in current node
        int cntWord; // occurance of word in current node
        TrieNode* children[ALPHABET_SIZE];
        TrieNode();
    };

private:
    TrieNode* root;

public:
    TrieTree();
    ~TrieTree();

    // build the trie-tree from a dictionary of words
    void build(const vector<string>& dict);

    // insert a new word into the trie-tree
    void insert(const string& word);

    // query how many times this word appear?
    int query(const string& word) const;

    // delete all nodes in the tree
    void deleteTree(const TrieNode *r);
};

#endif
