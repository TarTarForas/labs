#include "tnode.h"
#include <string>
#include <fstream>

const char lowCh = 'a';
const char highCh = 'z';


string TNode::reverseStr(string const& inp) {
    string outp;
    int n = inp.length();
    for (int i = 0; i < n; i++)
        outp.push_back(inp[n-i-1]);
    return outp;
}

TNode::TNode() {
    fEow = false;
}

/*
void TNode::init() {
    fEow = false;
}
*/

bool TNode::add(string word) {
    bool result;
    if (word == "") {
        result = !fEow;
        fEow = true;        
    } else {
        char first = word[0];
        word = word.erase(0,1);
        result = fMas[first].add(word);
    }
    return result;
}

bool TNode::del(string &word) {

}

/*void TNode::getAllAndPrint(QListWidget *lw, string pref) {
    if (fEow)
        lw->addItem(QString::fromStdString(reverseStr(pref)));
    for (char c = lowCh; c <= highCh; c++) {
        if (fMas.find(c) != fMas.end()) {
            pref.push_back(c);
            fMas[c].getAllAndPrint(lw, pref);
            pref = pref.erase(pref.length()-1, 1);

        }
    }
}
*/
void TNode::printReverse(QListWidget *lw, string &pref) {
    if (fEow)// && word != "")
        lw->addItem(QString::fromStdString(reverseStr(pref)));
    for (char c = lowCh; c <= highCh; c++) {
        if (fMas.find(c) != fMas.end()) {
            pref.push_back(c);
            fMas[c].printReverse(lw, pref);
            pref = pref.erase(pref.length()-1,1);
        }

    }
}

bool TNode::hasNext(char c) {
    return fMas.find(c) != fMas.end();
}

 void* TNode::getNext(char c) {
    return &fMas[c];
}

void TNode::print(QListWidget *lw, string &word) {
    if (fEow)// && word != "")
        lw->addItem(QString::fromStdString(word));
    for (char c = lowCh; c <= highCh; c++) {
        if (fMas.find(c) != fMas.end()) {
            word.push_back(c);
            fMas[c].print(lw, word);
            word = word.erase(word.length()-1,1);
        }

    }

}
