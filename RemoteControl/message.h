#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <QByteArray>

#define mHeader     0xb0 //Fix header
#define mWrite      0x01 //Write request
#define mRead       0x02 //Read request
#define mArmed      0x03
#define mDisArmed   0x04
#define mSERVO1     0xa0
#define mSERVO2     0xa1
#define mSERVO3     0xa2
#define mSERVO4     0xa3
#define mData       0xe1

#define MaxPayload 1024

//message len max is 256, header, command, rw and cheksum total len is 8, therefore payload max len is 248
//max input bluetooth buffer in this chip allows a payload max 0x38

typedef struct {
    uint8_t header;
    uint8_t len;
    uint8_t rw;
    uint8_t command;
    uint8_t data[MaxPayload];
    uint8_t CheckSum[2];
} MessagePack;


class Message
{
public:
    Message();
    bool parse(uint8_t *dataUART, uint8_t size, MessagePack *message);
    uint8_t create_pack(uint8_t RW,uint8_t command, QByteArray dataSend, uint8_t *dataUART);

};

#endif // MESSAGE_H
