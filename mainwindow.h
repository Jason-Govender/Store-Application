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
    QAction* file;
    QAction* restore;
    QAction* about;
    QAction* help;

private slots:
    void showAbout();
    void showHelp();
    void showRestore();

};
#endif // MAINWINDOW_H
