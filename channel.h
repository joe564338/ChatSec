#ifndef CHANNEL
#define CHANNEL
#include <string>
using namespace::std;
class Channel{
public:
    Channel(string channelName);
    bool Connect();
    bool Disconnect();
    string GetChannelName();
    bool mIsConnected = false;
private:
    string mChannelName;

};

#endif // CHANNEL

