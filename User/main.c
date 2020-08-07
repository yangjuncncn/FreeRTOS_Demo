/*
*****************************************
*						包含的头文件
*****************************************
*/
#include "list.h"
#include <stdio.h>

/*
*****************************************
*						全局变量
*****************************************
*/
struct xLIST List_Test;

struct xLIST_ITEM List_Item1;
struct xLIST_ITEM List_Item2;
struct xLIST_ITEM List_Item3;

uint32_t flag1;
uint32_t flag2;
void delay(uint32_t count);
    
/*
*****************************************
*						main()
*****************************************
*/

void delay(uint32_t count)
{
    for(;count != 0;count--);

}

int main(void)
{
	vListInitialise(&List_Test);
    
    vListInitialiseItem(&List_Item1);
    List_Item1.xItemValue = 1;
    vListInitialiseItem(&List_Item2);
    List_Item2.xItemValue = 2;
    vListInitialiseItem(&List_Item3);
    List_Item3.xItemValue = 3;
    
    vListInsert(&List_Test,&List_Item1);
    vListInsert(&List_Test,&List_Item2);
    vListInsert(&List_Test,&List_Item3);
    
    for(;;)
    {   
        printf("jfiejfiejfiejfiejf");
        flag1 = 1;
        delay(100);
        flag1 = 0;
        delay(100);
        
        flag2 = 1;
        delay(100);
        flag2 = 0;
        delay(100);
        
        
    }
}