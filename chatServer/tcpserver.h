#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QTextEdit>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <iostream>
//#include "server.h"

class TcpServer: public QDialog {
    Q_OBJECT
public:
    TcpServer(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~TcpServer();

public:
    QListWidget *listWidgetContent;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonCreate;
    QLineEdit *sendMsgEdit;
    QPushButton *pushButtonSendMsg;
    int port;
    //huiwu_liu
    QTcpServer *tcpServer;
    QTcpSocket *client;
    //Server *server;
public slots:
    void slotCreateServer();
    //void updateServer(QString,int);
    //huiwu_liu
    void slotSendMsgToClient();

    void acceptConnection();
    void startRead();


};

#endif // TCPSERVER_H
