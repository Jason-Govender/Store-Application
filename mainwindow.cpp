#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

    mainView = new QTreeView(this);

    //Define actions and add to toolbar
    addItem = new QAction("Add", this);
    file = new QAction("File", this);
    restore = new QAction("Restore", this);
    about = new QAction("About", this);
    help = new QAction("Help", this);
    toolbar = addToolBar("Main Toolbar");
    toolbar->addAction(file);
    toolbar->addAction(addItem);
    toolbar->addAction(restore);
    toolbar->addAction(about);
    toolbar->addAction(help);

    store = new Inventory();
    customerModel = new QStandardItemModel(this);
    customerModel->setHorizontalHeaderLabels(QStringList() << "Transaction" << "Type" << "Quantity");

    //Generates the customer list in the main menu.
    for (Customer* c : store->getCustomers() ){
        QStandardItem* customer = new QStandardItem(c->getName());
        customerModel->appendRow(customer);
    }
    connect(about, &QAction::triggered, this, &MainWindow::showAbout);
    connect(help, &QAction::triggered, this, &MainWindow::showHelp);
    connect(restore, &QAction::triggered, this, &MainWindow::showRestore);
    mainView->setModel(customerModel);
    setCentralWidget(mainView);

}

MainWindow::~MainWindow() {}

void MainWindow::showAbout(){

    QFile file(":/about.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString text = file.readAll();
        QMessageBox::about(this, "About", text);
    } else {
        QMessageBox::warning(this, "Error", "Could not load");
    }
}

void MainWindow::showHelp(){

    QFile file(":/help.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString text = file.readAll();
        QMessageBox::about(this, "Help", text);
    } else {
        QMessageBox::warning(this, "Error", "Could not load");
    }
}

void MainWindow::showRestore(){
    for (Item* item : store->getItems())
        delete item;
    store->getItems().clear();


    for (Item* backup : store->getBackup())
        store->getItems().append(new Item(*backup));
    QMessageBox::about(this, "Restore", "Inventory Successfully Restored");
}








