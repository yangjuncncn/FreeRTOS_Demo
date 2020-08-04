#include "portmacro.h"

struct xLIST_ITEM
{
    TickType_t xItemValue;      /*�ڵ�������ֵ*/
    struct xLIST_ITEM * pxNext;     /*ָ����һ�ڵ�ָ��*/
    struct xLIST_ITEM * pxPrevious;     /*��һ�ڵ�*/
    void * pvOwner;                 /*ָ��ӵ�иĽڵ���ں˶���ͨ����TCB*/
    void * pvContainer;             /*ָ��ýڵ����ڵ�����*/
    
};
typedef struct xLIST_ITEM ListItem_t; /*�ڵ������ض���*/

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