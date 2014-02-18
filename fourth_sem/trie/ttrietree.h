#ifndef TTRIETREE_H
#define TTRIETREE_H

#include "tnode.h"

class TTrieTree {
private:
    TNode fRoot;
public:
    //TTrieTree();
    bool add(string word);
    bool del(string& word);
    void printToQLW(QListWidget *lw);
    bool search(QListWidget *lw, string pref);

};

#endif // TTRIETREE_H
