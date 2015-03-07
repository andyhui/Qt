#include <QApplication>
#include <QTranslator>
#include "tcpserver.h"

int main(int argc, char **argv){
    QApplication app(argc,argv);
    QTranslator trans;
    trans.load("../TcpServer/tcpserver_zh.qm");
    app.installTranslator(&trans);
    TcpServer tcpServer;
    tcpServer.show();
    return app.exec();
}
