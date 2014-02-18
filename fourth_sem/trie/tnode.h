#ifndef TNODE_H
#define TNODE_H

#include <map>
#include <algorithm>
#include <string>
#include <fstream>
#include <QListWidget>

using namespace std;

class TNode;

typedef map<char, TNode> array;

class TNode {
private:
    array fMas;
    bool fEow;    
    //void getAllAndPrint(QListWidget *lw, string pref);
public:
    TNode();  //constructor

    void init();
    bool add(string word);
    bool del(string &word);
    void printReverse(QListWidget *lw, string &pref);
    void print(QListWidget *lw, string &word);

    bool hasNext(char c);
    void* getNext(char c);

    static string reverseStr(string const& inp);

};

#endif // TNODE_H
