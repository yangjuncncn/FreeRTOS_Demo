#include "portmacro.h"
#include "FreeRTOSConfig.h"
#include "task.h"

TCB_t Task1TCB;
TCB_t Task2TCB;

#if(configSUPPORT_STATIC_ALLOCATION == 1)
TaskHandle_t xTaskCreateStatic(TaskFunction_t pxTaskCode,
                        const char * const pcName,
                        const uint32_t ulStackDepth,
                        void * const pvParameters,
                        StackType_t * const puxStackBuffer,
                        TCB_t * const pxTaskBuffer)
{
    TCB_t * pxNewTCB;
    TaskHandle_t xReturn;
    
    
    if((pxTaskBuffer != NULL )&&(puxStackBuffer != NULL))
    {
        pxNewTCB = (TCB_t*)pxTaskBuffer;
        pxNewTCB->pxStack = (StackType_t *)puxStackBuffer;
        
        prvInitialiseNewTask(pxTaskCode,pcName,ulStackDepth,pvParameters,&xReturn,pxNewTCB);
        
    }
    else
    {
        xReturn = NULL;
        
    }
    
    return xReturn;
    
    
                          
    

}

#endif

static void prvInitialiseNewTask(TaskFunction_t pxTaskCode,
                const char * const pcName,
                const uint32_t ulStackDepth,
                void * const pvParameters,
                TaskHandle_t * const pxCreatedTask,
                TCB_t * pxNewTCB)
{
    StackType_t * pxTopOfStack;
    UBaseType_t x;
    
    pxTopOfStack = pxNewTCB->pxStack +(ulStackDepth - (uint32_t)1);
    
    pxTopOfStack = (StackType_t *) \ (((uint32_t)pxTopOfStack)&(~((uint32_t) 0x0007)));
    
    for(x = (UBaseType_t) 0;x < (UBaseType_t) configMAX_TASK_NAME_LEN;x++)
    {
        pxNewTCB->pcTaskName[x] = pcName[x];
        
        if(pcName[x] == 0x00)
        {
            break;
        }
    }
    
    pxNewTCB->pcTaskName[configMAX_TASK_NAME_LEN - 1] = '\0';
    
    vListInitialise(&(pxNewTCB->xStatuListItem));
    
    listSET_LIST_ITEM_OWNER(&(pxNewTCB->xStateListItem),pxNewTCB);
    
    
    pxNewTCB->pxTopOfStack = pxPortInitialiseStack(pxTopOfStack,pxTaskCode,pvParameters);
    
    
    if((void*)pxCreatedTask != NUL)
    {
        *pxCreatedTask = (TaskHandle_t)pxNewTCB;
    }
}