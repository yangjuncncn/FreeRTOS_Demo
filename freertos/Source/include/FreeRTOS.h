#ifndef FREE_RTOS_H
#define FREE_RTOS_H
#include "portmacro.h"
#include "list.h"
#include "FreeRTOSConfig.h"
typedef struct tskTaskControlBlock
{
    volatile StackType_t *pxTopOfStack;
    ListItem_t xStatuListItem;
    StackType_t *pxStack;
    char pcTaskName[ configMAX_TASK_NAME_LEN];
}tskTCB;
typedef tskTCB TCB_t;

#endif