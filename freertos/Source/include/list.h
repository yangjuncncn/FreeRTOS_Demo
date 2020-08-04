#include "portmacro.h"

struct xLIST_ITEM
{
    TickType_t xItemValue;      /*节点排序辅助值*/
    struct xLIST_ITEM * pxNext;     /*指向下一节点指针*/
    struct xLIST_ITEM * pxPrevious;     /*上一节点*/
    void * pvOwner;                 /*指向拥有改节点的内核对象。通常是TCB*/
    void * pvContainer;             /*指向该节点所在的链表*/
    
};
typedef struct xLIST_ITEM ListItem_t; /*节点数据重定义*/

struct xMINI_LIST_ITEM
{
    TickType_t xItemValue;
    struct xLIST_ITEM * pxNext;
    struct xLIST_ITEM * pxPrevious;
   
};
typedef struct xMINI_LIST_ITEM MiniListItem_t;

typedef struct xLIST
{
    UBaseType_t uxNumberOfItems;
    ListItem_t * pxIndex;
    MiniListItem_t xListEnd;
}List_t;


void vListInitialiseItem(ListItem_t * const pxItem);
void vListInitialise(List_t * const pxList);
void vListInsertEnd(List_t * pxList,ListItem_t * const pxNewLIstItem);
void vListInsert(List_t * const pxList,ListItem_t * const pxNewListItem);