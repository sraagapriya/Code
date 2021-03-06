/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef HEAP_H_
#define HEAP_H_

struct heapNode
{
	unsigned int priority;
	struct heapNode* rightChild;
	struct heapNode* leftChild;
	struct heapNode* parent;
	int keyId;
};

typedef struct heapNode* HEAP;

int isHeapEmpty(HEAP head);
HEAP getHeapNode();
void freeHeapNode(HEAP oldNode);
void inOrderTraversal(HEAP rootNode);
void swapData(HEAP element1, HEAP element2,int* locationVector);
void heapifyDown(HEAP rootElement,int* locationVector);
void heapifyUp(HEAP rootElement,int* locationVector);
void addElementToHeap(HEAP rootElement, HEAP newElement, int count,int* locationVector);
void deleteElementFromHeap (HEAP rootElement, int count,int* locationVector);

#endif
