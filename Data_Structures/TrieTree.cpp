#include <cstring>
#include <string>
#include <vector>
#include "TrieTree.h"
using namespace std;

TrieTree::TrieNode::TrieNode():cntPrefix(0), cntWord(0)
{
    memset(children, 0, sizeof(children));
}

TrieTree::TrieTree()
{
    root = new TrieNode();
}

TrieTree::~TrieTree()
{
    deleteTree(root);
}

void TrieTree::build(const vector<string>& dict)
{
    for (int i=0; i<dict.size(); i++) {
        string word = dict[i];
        insert(word);
    }
}

void TrieTree::insert(const string& word)
{
    TrieNode *p = root;
    for (int i=0; i<word.size(); i++) {
        int idx = (int)word[i];
        if (p->children[idx] == NULL) {
            p->children[idx] = new TrieNode();
        }
        p = p->children[idx];
        p->cntPrefix ++;
    }
    p->cntWord ++;
}

int TrieTree::query(const string& word) const
{
    TrieNode *p = root;
    for (int i=0; i<word.size(); i++) {
        int idx = (int)word[i];
        if (p->children[idx] == NULL) return 0;
        p = p->children[idx];
    }
    return p->cntWord;
}

void TrieTree::deleteTree(const TrieNode *r)
{
    if (r == NULL) return;
    for (int i=0; i<ALPHABET_SIZE; i++) {
        if (r->children[i] != NULL) {
            deleteTree(r->children[i]);
        }
    }
    delete r;
}

