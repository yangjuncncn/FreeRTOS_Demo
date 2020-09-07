#include "portmacro.h"

#define listSET_LIST_ITEM_OWNER(pxListItem,pxOwner)\
    (pxListItem)->pvOwner = (void *)(pxOwner)
#define listGET_LIST_ITEM_OWNER(pxListItem)\
    ((pxListItem)->pvOwner)
#define listSET_LIST_ITEM_VALUE(pxListItem,xValue)\
    ((pxListItem)->xItemValue = (xValue))
#define listGET_LIST_ITEM_VALUE(pxListItem)\
    ((pxListItem)->xItemValue)
#define listGET_ITEM_VALUE_OF_HEAD_ENTRY(pxList)\
    (((pxList)->xListEnd).pxNext->xItemValue)
#define listGET_HEAD_ENTRY(pxList)\
    (((pxList)->xListEnd).pxNext)
#define listGET_NEXT(pxListItem)\
    ((pxListItem)->pxNext)
#define listGET_END_MARKER(pxList)\
    ((ListItem_t const *)(&((pxList)->xListEnd)))
#define listLIST_IS_EMPTY(pxList)\
    ((BaseType_t)((pxList)->uxNumberOfItmes == (UBaseType_t)0))
#define listCURRENT_LIST_LENGTH(pxList)\
    ((pxList)->uxNumberOfItems)
    
#define listGET_OWNER_OF_NEXT_ENTRY( pxTCB, pxList )\
    {\
    List_t * const pxConstList = (pxList);\
    (pxConstList)->pxIndex = (pxConstList)->pxIndex->pxNetx;\
    if(void *)(pxConstList)->pxIndex == (void *)&((pxConstList)->xListEnd))\
        {\
            (pxConstList)->pxIndex = (pxConstList)->pxIndex->pxNext;\
        }\
    \
    (pxTCB) = (pxConstList)->pxIndex->pvOwner;\
        \
    }\

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
UBaseType_t uxListRemove(ListItem_t * const pxItemToRemove);
