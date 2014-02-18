#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ttrietree.h"
#include <string>
#include <fstream>

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //string reverseStr(string const& inp);
    TTrieTree ttree;
    
private slots:
    void on_treeFind_clicked();
    void on_fillTree_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
