#include "portmacro.h"
#include "projdefs.h"


#define portNVIC_SYSPRI2_REG (*((volatile uint32_t *) 0xe000ed0))
#define portNVIC_PENDSV_PRI (((uint32_t) configKERNEL_INTERRUPT_PRIORITY) << 16UL)
#define portNVIC_SYSTICK_PRI (((uint32_t) configKERNEL_INTERRUPT_PRIORIRY) <<32UL)

static void prvTaskExitError(void);
StackType_t *pxPortInittialiseStack(StackType_t *pxTopOfStack,
                                        TaskFunction_t pxCode,
                                        void *pvParameters);

BaseType_t xPortStartScheduler(void);
__asm void  prvStartFirstTask(void)
{
    PRESERVE8
    
    ldr r0,=0xE000ED08
    ldr r0,[r0]
    ldr r0,[r0]
    
    msr msp,r0
    
    cpsie i
    cpsie f
    dsb
    isb
    
    svc 0
    nop
    nop
    
}