#include "channel.h"
Channel::Channel(string channelName, string channelPassword){
    mChannelName = channelName;
    mChannelPassword = channelPassword;
}
Channel::Connect(){
    return mIsConnected;
}
Channel::Disconnect(){
    return mIsConnected;
}
Channel::GetChannelName(){
    return mChannelName;
}
