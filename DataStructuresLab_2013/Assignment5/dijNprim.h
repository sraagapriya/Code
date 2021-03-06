/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef DIJNPRIM_H_
#define DIJNPRIM_H_

void insertElement(int keyId, int priority, HEAP priorityQueueRoot,int* locationVector);
HEAP createPriorityQueue(LINKED_LIST* vertex,int count,int* locationVector);
void changePrimsPriority(int position,int newPriority, int* locationVector,HEAP rootElement, int* prevNode, int deletedKeyWeight,int toBeDeletedKey);
void changeDijkastraPriority(int position,int newPriority, int* locationVector,HEAP rootElement, int* prevNode, int deletedKeyWeight,int toBeDeletedKey);
void prims(LINKED_LIST *vertex, HEAP priorityQueueRoot,int *locationVector,int *prevNode,int startingNode,int* weightArray,int *outputArray, int i);
void dijkastra(LINKED_LIST *vertex, HEAP priorityQueueRoot,int *locationVector,int *prevNode,int startingNode,int* weightArray);

#endif
