#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    store = new Inventory();
    mainView = new QTreeView(this);
    customerModel = new QStandardItemModel(this);
    customerModel->setHorizontalHeaderLabels(QStringList() << "Transaction" << "Type" << "Quantity");
    for (Customer* c : store->getCustomers() ){
        QStandardItem* customer = new QStandardItem(c->getName());
        customerModel->appendRow(customer);
    }
    mainView->setModel(customerModel);
    setCentralWidget(mainView);
}

MainWindow::~MainWindow() {}






