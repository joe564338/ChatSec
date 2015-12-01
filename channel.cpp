#include "channel.h"
Channel::Channel(string channelName){
    mChannelName = channelName;

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
