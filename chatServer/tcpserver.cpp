#include "tcpserver.h"

TcpServer::TcpServer(QWidget *parent, Qt::WindowFlags f): QDialog(parent,f){
    setWindowTitle(tr("TCP Server"));

    QVBoxLayout *vbMain = new QVBoxLayout(this);

    listWidgetContent = new QListWidget(this);
    vbMain->addWidget(listWidgetContent);

    QHBoxLayout *hb = new QHBoxLayout;
    labelPort = new QLabel(tr("Port:"));
    hb->addWidget(labelPort);
    lineEditPort = new QLineEdit;
    hb->addWidget(lineEditPort);
    vbMain->addLayout(hb);

    pushButtonCreate = new QPushButton(tr("Create"));
    vbMain->addWidget(pushButtonCreate);

    sendMsgEdit = new QLineEdit(this);
    vbMain->addWidget(sendMsgEdit);

    pushButtonSendMsg = new QPushButton(tr("SendMsg"));
    vbMain->addWidget(pushButtonSendMsg);

    connect(pushButtonCreate,SIGNAL(clicked()),this,SLOT(slotCreateServer()));
    port = 8010;
    lineEditPort->setText(QString::number(port));

    //huiwu_liu
    connect(pushButtonSendMsg,SIGNAL(clicked()),this,SLOT(slotSendMsgToClient()));
}

TcpServer::~TcpServer(){
    tcpServer->close();
    client->close();
}

void TcpServer::slotCreateServer(){
    //server = new Server(this,port);
    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    tcpServer->listen(QHostAddress::Any, port);
    //connect(server,SIGNAL(updateServer(QString,int)),this,SLOT(updateServer(QString,int)));
    pushButtonCreate->setEnabled(false);
}

void TcpServer::acceptConnection(){
    client = tcpServer->nextPendingConnection();
    connect(client, SIGNAL(readyRead()),
        this, SLOT(startRead()));

}

void TcpServer::startRead(){
    char buffer[1024] = {0};
    client->read(buffer, client->bytesAvailable());
    QString msg = QString::fromStdString(buffer);
    listWidgetContent->addItem(msg);
    //client->close();

}


void TcpServer::slotSendMsgToClient(){
    printf("hello world!\n");
    QString msg = sendMsgEdit->text();
    client->write(msg.toLatin1(),msg.length());
    sendMsgEdit->clear();

}
