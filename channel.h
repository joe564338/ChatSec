#ifndef CHANNEL
#define CHANNEL
#include <string>
using namespace::std;
class Channel{
public:
    Channel(string channelName, string channelPassword);
    bool Connect();
    bool Disconnect();
    string GetChannelName();
    bool mIsConnected = false;
private:
    string mChannelName;
    string mChannelPassword;
};

#endif // CHANNEL

