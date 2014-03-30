#include <iostream>
#include <string>
#include <vector>
#include "Data_Structures/TrieTree.h"
using namespace std;

int main()
{
    cout << "input dict:" << endl;
    vector<string> dict;
    string w;
    while (true) {
        cin >> w;
        if (w == "END") break;
        dict.push_back(w);
    }

    TrieTree trie;
    trie.build(dict);

    cout << "input query:" << endl;
    while (cin >> w) {
        cout << trie.query(w) << endl;
    }

    return 0;
}
