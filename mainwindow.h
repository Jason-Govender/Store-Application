#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTreeView>
#include <QMainWindow>
#include <QStandardItemModel>
#include "inventory.h"
#include <QToolBar>
#include <QAction>
#include <QMessageBox>
#include <QFile>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QListWidget>
#include <QGridLayout>

/* This is where the toolbar and action buttons are defined.
 * The default constructor is used to implement the entire
 * user interface.
 * An inventory variable is used to interact with all of our
 * classes.*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /* Performs a real-time update to the transaction history
     * window once a transaction is processed successfully.*/
    void updateMainView();

private:
    QTreeView* mainView;
    QStandardItemModel* customerModel;
    Inventory* store;
    QToolBar* toolbar;
    QAction* addItem;
    QAction* transact;
    QAction* restore;
    QAction* about;
    QAction* help;

private slots:
/*  Opens a dialog to record a transaction.
    Handles quantity validation and updates the inventory upon success.*/
    void showTransact();

    void showAbout();

    void showHelp();

    void showRestore();

/*  Opens a dialog for adding a new item to the inventory.
    On acceptance, item is added and a backup copy is stored.*/
    void showAddItem();

};
#endif // MAINWINDOW_H
