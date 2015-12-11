#ifndef CHANNEL
#define CHANNEL
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QString>
#include <QByteArray>
#include <string>
#include <QUrlQuery>
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <thread>
#include <chrono>
#include <QWidget>
#include <QtWebSockets/QWebSocket>
//Class for handling connections
using namespace::std;
class Channel : public QObject {
    Q_OBJECT
public:
    Channel(string channelName);//Constructor for channel
    bool Connect();//connects to chat server
    bool Disconnect();//disconnects from chat server
    string GetChannelName();//returns the name of the channel
    bool mIsConnected = false;//used for connection checking
    void UploadKeys(std::string user, char *privKey, char *publicKey);
    char* encryptKey;
    QWebSocket sender;
private:
    void onConnect();
    string mChannelName;
    QNetworkAccessManager networkManager;
private slots:
    void parseNetworkResponse( QNetworkReply *finished );
};

#endif // CHANNEL

