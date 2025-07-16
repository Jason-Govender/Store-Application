#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTreeView>
#include <QMainWindow>
#include <QStandardItemModel>
#include "inventory.h"

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
};
#endif // MAINWINDOW_H
