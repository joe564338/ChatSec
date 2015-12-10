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
using namespace::std;
class Channel : public QObject {
    Q_OBJECT
public:
    Channel(string channelName);
    bool Connect();
    bool Disconnect();
    string GetChannelName();
    bool mIsConnected = false;
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

