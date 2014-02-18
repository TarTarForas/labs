#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_treeFind_clicked() {
    ui->resultWordList->clear();

    string suffix = ui->suffix->text().toStdString();
    string prefix = TNode::reverseStr(suffix);
    ttree.search(ui->resultWordList, prefix);
}

void MainWindow::on_fillTree_clicked() {

    ui->fileWordList->clear();
    ui->treeWordList->clear();
    ui->resultWordList->clear();

    string fname = ui->filename->text().toStdString();
    //открытие файла на чтение
    ifstream fin(fname.c_str());
    string tmpwrd;
    while (fin >> tmpwrd) {
        ui->fileWordList->addItem(QString::fromStdString(tmpwrd));
        //переворачиваем слово
        tmpwrd = TNode::reverseStr(tmpwrd);
        if (ttree.add(tmpwrd))
            ui->treeWordList->addItem(QString::fromStdString(tmpwrd));
    }
    ttree.printToQLW(ui->treeWordList);

}
