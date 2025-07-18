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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
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
    void showTransact();
    void showAbout();
    void showHelp();
    void showRestore();
    void showAddItem();

};
#endif // MAINWINDOW_H
