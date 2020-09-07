#include "port.h"

#define portINITLAL_XPSR (0x01000000)
#define portSTART_ASSRESS_MASK ((StackType_t) 0xfffffffeUL)

static void  prvTaskExitError(void)
{
    for(;;);
}

StackType_t *pxPortInittialiseStack(StackType_t *pxTopOfStack,
                                        TaskFunction_t pxCode,
                                        void *pvParameters)
{
    pxTopOfStack--;
    *pxTopOfStack = portINITLAL_XPSR;
    pxTopOfStack--;
    *pxTopOfStack = ((StackType_t)pxCode) & portSTART_ASSRESS_MASK;
    pxTopOfStack--;
    *pxTopOfStack = (StackType_t)prvTaskExitError;
    pxTopOfStack -= 5;
    *pxTopOfStack = (StackType_t) pvParameters;
    
    pxTopOfStack -= 8;
    return pxTopOfStack;
}                                                                                
BaseType_t xPortStartScheduler(void)
{
    portNVIC_SYSPRI2_REG |= portNVIC_PENDSV_PRI;
    portNVIC_SYSPRI2_REG |= portNVIC_SYSTICK_PRI;
}    

