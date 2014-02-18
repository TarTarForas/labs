#include "ttrietree.h"

bool TTrieTree::add(string word) {
    bool result = fRoot.add(word);
    return result;
}

bool TTrieTree::del(string &word) {
    return fRoot.del(word);
}

void TTrieTree::printToQLW(QListWidget *lw) {
    lw->clear();
    string s = "";
    fRoot.print(lw, s);
}

bool TTrieTree::search(QListWidget *lw, string pref) {

    bool ok = true;
    TTrieTree *sub = this;
    int len = pref.length();
    int i = 0;
    while (ok && i < len) {
        //есть такая буква в массиве
        ok = sub->fRoot.hasNext(pref[i]);
        if (ok)
            sub = (TTrieTree*)sub->fRoot.getNext(pref[i]);
        i++;
    }
    if (ok)
        sub->fRoot.printReverse(lw, pref);

    //fRoot.search(lw, pref);

}
