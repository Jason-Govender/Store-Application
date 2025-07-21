#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QTimer>
#include <QLabel>
Q_DECLARE_METATYPE(Customer*)
Q_DECLARE_METATYPE(Item*)

//Displays the mainwindow and implements a timed splashscreen.
//Sets a window icon.
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/icon.png"));
    QPixmap pixmap(":/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();
    app.processEvents();
    QTimer::singleShot(2000, &splash, &QSplashScreen::close);
    MainWindow w;
    QTimer::singleShot(2000, [&]() {
        splash.finish(&w);
        w.show();
    });
    return app.exec();
}
