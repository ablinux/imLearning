#include <stdio.h>
#include <stdint.h>

#define MSGTYPE_INDEX   (0U)
#define MSGTYPE_SIZE    (1U)

#define TRACEID_INDEX   MSGTYPE_SIZE  + MSGTYPE_INDEX
#define TRACEID_SIZE    (2U)

#define ARGS_INDEX      TRACEID_INDEX + TRACEID_SIZE
#define ARGS_SIZE       (4U)

#define VALUE1_INDEX    ARGS_INDEX    + ARGS_SIZE
#define VALUE1_SIZE     (4U)

#define VALUE2_INDEX    VALUE1_INDEX  + VALUE1_SIZE
#define VALUE2_SIZE     (4U)

#define VALUE3_INDEX    VALUE2_INDEX  + VALUE2_SIZE
#define VALUE3_SIZE     (4U)

#define VALUE4_INDEX    VALUE3_INDEX  + VALUE3_SIZE
#define VALUE4_SIZE     (4U)

#define TRACEBUFFER_SIZE MSGTYPE_SIZE+TRACEID_SIZE+ARGS_SIZE+VALUE1_SIZE+VALUE2_SIZE+VALUE3_SIZE+VALUE4_SIZE

uint8_t traceBuffer[TRACEBUFFER_SIZE];

int main()
{
    traceBuffer[MSGTYPE_INDEX] = 0x01;

    traceBuffer[TRACEID_INDEX] = (0x2345>>8)&0xff; 
    traceBuffer[TRACEID_INDEX+1] = 0x2345&0x00ff;

    traceBuffer[ARGS_INDEX] = (0x6789ABCD>>24)&0xff;
    traceBuffer[ARGS_INDEX+1] = (0x6789ABCD>>16)&0xff;
    traceBuffer[ARGS_INDEX+2] = (0x6789ABCD>>8)&0xff;
    traceBuffer[ARGS_INDEX+3] = 0x6789ABCD&0xff;

    traceBuffer[VALUE1_INDEX] =   (0x12345678>>24)&0xff;
    traceBuffer[VALUE1_INDEX+1] = (0x12345678>>16)&0xff;
    traceBuffer[VALUE1_INDEX+2] = (0x12345678>>8)&0xff;
    traceBuffer[VALUE1_INDEX+3] =  0x12345678&0xff;


    traceBuffer[VALUE2_INDEX] =   (0x12345678>>24)&0xff;
    traceBuffer[VALUE2_INDEX+1] = (0x12345678>>16)&0xff;
    traceBuffer[VALUE2_INDEX+2] = (0x12345678>>8)&0xff;
    traceBuffer[VALUE2_INDEX+3] =  0x12345678&0xff;

    traceBuffer[VALUE3_INDEX] =   (0x12345678>>24)&0xff;
    traceBuffer[VALUE3_INDEX+1] = (0x12345678>>16)&0xff;
    traceBuffer[VALUE3_INDEX+2] = (0x12345678>>8)&0xff;
    traceBuffer[VALUE3_INDEX+3] =  0x12345678&0xff;

    traceBuffer[VALUE4_INDEX] =   (0x12345678>>24)&0xff;
    traceBuffer[VALUE4_INDEX+1] = (0x12345678>>16)&0xff;
    traceBuffer[VALUE4_INDEX+2] = (0x12345678>>8)&0xff;
    traceBuffer[VALUE4_INDEX+3] =  0x12345678&0xff;
    printf("\n");
    for(int i=0; i<TRACEBUFFER_SIZE; i++)
    {
        printf("-%x-",traceBuffer[i]);
    }


}