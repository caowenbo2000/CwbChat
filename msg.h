#ifndef MSG_TEST_H
#define MSG_TEST_H


#define ByteNumber 284
struct MsgFormat
{
    int SenderID;
    int RecverID;
    char MsgTime[20]; //2016-01-07T14:36:16
    char MsgContent[256];
};//28 + 256 = 284





#endif // MSG_TEST_H
