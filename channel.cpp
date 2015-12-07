#include "channel.h"

Channel::Channel(string channelName){
    mChannelName = channelName;
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(parseNetworkResponse(QNetworkReply*)));
}
bool Channel::Connect(){
    return mIsConnected;
}
bool Channel::Disconnect(){
    return mIsConnected;
}
string Channel::GetChannelName(){
    return mChannelName;
}
void Channel::UploadKeys(std::string user, char* privKey, char* publicKey){
    /*QNetworkAccessManager *nwam = new QNetworkAccessManager;

    QNetworkRequest request(QUrl("http://csks.ckrz.de/api/v1.0/keys/test1"));

    QByteArray data;
    QUrlQuery params;
    std::cout << "Sometin" << std::endl;
    QString userString = QString::fromUtf8(user.c_str());
    QString signingKeyString = QString::fromUtf8(privKey);
    QString publicKeyString = QString::fromUtf8(publicKey);
    params.addQueryItem("username", userString );
    params.addQueryItem("signing_key", signingKeyString );
    params.addQueryItem("encryption_key", publicKeyString);
    data.append(params.toString());
    data.remove(0,1);
    */


    QUrl url("http://csks.ckrz.de/api/v1.0/keys/test1");
    QNetworkRequest request;
    request.setUrl(url);
    //connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(parseNetworkResponse(QNetworkReply*)));
    QNetworkReply* currentReply = networkManager.get(request);  // GET
    std::cout << "hi joe 123" << std::endl;

std::cout << "1-.-.-.-23" << std::endl;

/*
    //QNetworkReply *reply = nwam->post(request,data);
    QNetworkReply *reply2 = nwam->get(request);
    connect(nwam, SIGNAL(finished(reply2)),
                      this, SLOT(parseNetworkResponse(reply2)));


    //QByteArray keyStuff = reply2->readAll();
    //QString encKey = QString::fromUtf8(keyStuff.data(), keyStuff.size());
    //QJsonDocument jsonDoc = QJsonDocument::fromJson(keyStuff);
    //QJsonObject jsonObj = jsonDoc.object();
    //QString encKey = jsonObj["encryption_key"].toString();
    //std::string s = encKey.toUtf8();
    //std::cout << s << std::endl;
    std::cout << "KEY" << std::endl;
*/
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
    //emit jokeReady( data );
}
/*
// Fragments from ChuckNorrisAPI.cpp
ChuckNorrisAPI::ChuckNorrisAPI(QObject *parent) :
    QObject(parent)
{
    QObject::connect(&m_nam, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(parseNetworkResponse(QNetworkReply*)));
}

void ChuckNorrisAPI::getRequest( const QString &urlString )
{
    QUrl url ( urlString );
    QNetworkRequest req ( url );
    m_nam.get( req );
}
void ChuckNorrisAPI::parseNetworkResponse( QNetworkReply *finished )
{
    if ( finished->error() != QNetworkReply::NoError )
    {
        // A communication error has occurred
        emit networkError( finished->error() );
        return;
    }

    // QNetworkReply is a QIODevice. So we read from it just like it was a file
    QByteArray data = finished->readAll();
    emit jokeReady( data );
}*/
