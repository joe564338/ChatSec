#include "channel.h"

Channel::Channel(string channelName){
    mChannelName = channelName;
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(parseNetworkResponse(QNetworkReply*)));
}
//connects to chat server
bool Channel::Connect(){
    connect(&sender, &QWebSocket::connected, this, &Channel::onConnect);
    sender.open(QUrl("ws://localhost:1234"));

    sender.sendTextMessage(QString("test"));
    return mIsConnected;
}
//not fully implemented yet
bool Channel::Disconnect(){
    return mIsConnected;
}
string Channel::GetChannelName(){
    return mChannelName;
}

void Channel::onConnect(){
    std::cout << "HI" << std::endl;
}
//Connect to key server for uploading keys as well as retrieving desired public key
void Channel::UploadKeys(std::string user, char* privKey, char* publicKey){
    QNetworkAccessManager *nwam = new QNetworkAccessManager;

    QNetworkRequest requestPoster(QUrl("http://csks.ckrz.de/api/v1.0/keys"));

    QByteArray data;
    QUrlQuery params;
    std::cout << "Sometin" << std::endl;
    QString userString = QString::fromUtf8(user.c_str());
    QString signingKeyString = QString::fromUtf8("");
    QString publicKeyString = QString::fromUtf8(publicKey);
    std::string tester = userString.toUtf8();
    std::cout << tester << std::endl;
    params.addQueryItem(" username", userString );
    params.addQueryItem("signing_key", signingKeyString );
    params.addQueryItem("encryption_key", publicKeyString);
    data.append(params.toString());
    data.remove(0,1);



    QUrl url("http://csks.ckrz.de/api/v1.0/keys/test1");
    QNetworkRequest request;
    request.setUrl(url);
    QNetworkReply* currentReply = networkManager.get(request);  // GET
    std::cout << "hi joe 123" << std::endl;

std::cout << "1-.-.-.-23" << std::endl;


    QNetworkReply *reply = nwam->post(requestPoster,data);

}

void Channel::parseNetworkResponse( QNetworkReply* finished )
{



    if ( finished->error() != QNetworkReply::NoError )
    {
        // A communication error has occurred
        //emit networkError( finished->error() );
        std::string c = finished->errorString().toUtf8();
        std::cout << c << std::endl;
        return;
    }


    // QNetworkReply is a QIODevice. So we read from it just like it was a file
    QByteArray data = finished->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    QJsonObject jsonObj = jsonDoc.object();
    QString encKey = jsonObj["encryption_key"].toString();
    std::string s = encKey.toUtf8();
    std::cout << s << std::endl;
    mIsConnected = true;
}

