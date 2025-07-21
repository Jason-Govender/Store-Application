#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

    mainView = new QTreeView(this);
    store = new Inventory();

    //Define actions and add to toolbar
    addItem = new QAction("Add", this);
    transact = new QAction("Transact", this);
    restore = new QAction("Restore", this);
    about = new QAction("About", this);
    help = new QAction("Help", this);
    toolbar = addToolBar("Main Toolbar");
    toolbar->addAction(transact);
    toolbar->addAction(addItem);
    toolbar->addAction(restore);
    toolbar->addAction(about);
    toolbar->addAction(help);

    //Provides a model for the treeview and separates the model into three columns.
    customerModel = new QStandardItemModel(this);
    customerModel->setHorizontalHeaderLabels(QStringList() << "Transaction" << "Type" << "Quantity");

    //Provides functionality to action button presses
    connect(about, &QAction::triggered, this, &MainWindow::showAbout);
    connect(help, &QAction::triggered, this, &MainWindow::showHelp);
    connect(restore, &QAction::triggered, this, &MainWindow::showRestore);
    connect(addItem, &QAction::triggered, this, &MainWindow::showAddItem);
    connect(transact, &QAction::triggered, this, &MainWindow::showTransact);
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
    store->restoreItems();
    QMessageBox::about(this, "Restore", "Inventory Successfully Restored");
}

void MainWindow::showAddItem(){
    //Creates the window, dropdown box and input field.
    QDialog dialog(this);
    dialog.setWindowTitle("Add Item");
    QVBoxLayout* layout = new QVBoxLayout(&dialog);
    QLabel* prompt = new QLabel("Enter item details below:");
    layout->addWidget(prompt);
    QComboBox* typeCombo = new QComboBox();
    typeCombo->addItem("Book");
    typeCombo->addItem("Magazine");
    layout->addWidget(typeCombo);
    QLineEdit* input = new QLineEdit();
    input->setPlaceholderText("Item name");
    layout->addWidget(input);
    QPushButton* addButton = new QPushButton("Add Item");
    layout->addWidget(addButton);

    //Checks to see if the input ais invalid (empty).
    connect(addButton, &QPushButton::clicked, this, [&]() {
        if (input->text().isEmpty()) {
            QMessageBox::warning(&dialog, "Invalid Input", "Please enter a valid name");
            return;
        }
        else{
            dialog.accept();
        }
    });

    //Confirms input and adds to the backup list.
    if (dialog.exec() == QDialog::Accepted) {
        Item* item = new Item(input->text(), typeCombo->currentText());
        store->addItem(item);
        store->getBackup()=store->getItems();
    }
}


void MainWindow::showTransact(){
    //Generates window and input field.
    QDialog display(this);
    display.setWindowTitle("Transaction");
    QGridLayout* layout = new QGridLayout(&display);
    QLabel* prompt = new QLabel("Enter transaction details below:");
    layout->addWidget(prompt, 0,1);
    QComboBox* customer = new QComboBox(&display);
    for (Customer* c : store->getCustomers()){
        customer->addItem(c->getName(), QVariant::fromValue(c));
    }
    layout->addWidget(new QLabel("Customer:"), 1,0);
    layout->addWidget(customer, 1,1);
    QComboBox* itemName = new QComboBox(&display);
    for (Item* item : store->getItems()){
        itemName->addItem(item->getName(), QVariant::fromValue(item));
    }
    layout->addWidget(new QLabel("Item Name:"), 2,0);
    layout->addWidget(itemName, 2,1);
    QSpinBox* quantity = new QSpinBox(&display);
    quantity->setMinimum(1);
    quantity->setMaximum(100);
    quantity->setValue(1);
    quantity->setSingleStep(1);
    layout->addWidget(new QLabel("Quantity:"), 3,0);
    layout->addWidget(quantity, 3,1);
    QPushButton* addButton = new QPushButton("Add");
    layout->addWidget(addButton, 4,1);
    QListWidget* list = new QListWidget(&display);
    layout->addWidget(list, 5,1);
    QPushButton* transactButton = new QPushButton("Transact");
    layout->addWidget(transactButton, 6,1);

    //Validates input when trying to add items to cart. Displays valid transactions
    //on the bottom menu.
    connect(addButton, &QPushButton::clicked, this, [&](){
        Customer* cP = customer->currentData().value<Customer*>();
        Item* iP = itemName->currentData().value<Item*>();

        if (!iP) {
            QMessageBox::warning(&display, "Invalid Item", "The selected item is no longer available.");
            return;
        }

        Transaction* transaction = new Transaction();
        transaction->setCustomer(cP);
        transaction->setItem(iP);
        transaction->setQuantity(quantity->value());
        transaction->setDateTime(QDateTime::currentDateTime());

        QString c = transaction->getCustomer()->getName();
        QString i = transaction->getItem()->getName();
        int q = transaction->getQuantity();
        QDateTime dt = transaction->getdateTime();

        if( store->processTransaction(&display, *transaction)){
            QString statement = c + " " + i + " " + QString::number(q) + " " + dt.toString("yyyy-MM-dd hh:mm:ss");

            list->addItem(statement);
            store->addTransaction(transaction);
        }
        else{
            delete transaction;
            return;
        }
    });

    //Confirms transaction and updates transaction history treeview.
    connect(transactButton, &QPushButton::clicked, this, [&](){
        display.accept();
        updateMainView();
    });

    display.exec();
}

void MainWindow::updateMainView(){
    customerModel->clear();
    customerModel->setHorizontalHeaderLabels(QStringList() << "Transaction" << "Type" << "Quantity");
    for (Customer* c : store->getCustomers()){
        QStandardItem* cItem = new QStandardItem(c->getName());
        for(Transaction* t : store->getTransactions()){
            if (t->getCustomer() == c) {
                QString dateTime = t->getdateTime().toString("yyyy-MM-dd hh:mm:ss");
                QStandardItem* dateItem = nullptr;
                for (int i = 0; i < cItem->rowCount(); ++i) {
                    QStandardItem* child = cItem->child(i);
                    if (child->text() == dateTime) {
                         dateItem = child;
                        break;
                    }
                }


                if (!dateItem) {
                    dateItem = new QStandardItem(dateTime);
                    cItem->appendRow(dateItem);
                }

                QList<QStandardItem*> transactionRow;
                QStandardItem* itemName = new QStandardItem(t->getItem()->getName());
                QStandardItem* itemType = new QStandardItem(t->getItem()->getType());
                QStandardItem* quantity = new QStandardItem(QString::number(t->getQuantity()));
                transactionRow << itemName << itemType << quantity;
                dateItem->appendRow(transactionRow);
            }
        }

        customerModel->appendRow(cItem);
    }

}






