/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#ifndef _LINKEDLIST
#define _LINKEDLIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"
#endif
#define TRUE 1
#define FALSE 0
struct heapNode
{
	unsigned int priority;
	struct heapNode* rightChild;
	struct heapNode* leftChild;
	struct heapNode* parent;
	char name[21];
};

typedef struct heapNode* HEAP;

int isHeapEmpty(HEAP head)
{
	if(head==NULL)
	{
		return TRUE;
	}
	else
		return FALSE;

	return TRUE;
}

HEAP getHeapNode()
{
	HEAP newNode;
	newNode=(HEAP)malloc(sizeof(struct heapNode));
	
	return newNode;
}

void freeHeapNode(HEAP oldNode)
{
	free(oldNode);
}

void inOrderTraversal(HEAP rootNode)
{
	if(rootNode->leftChild!=NULL)
		inOrderTraversal(rootNode->leftChild);

	printf("Priority: %d\nName: %s\n\n",rootNode->priority,rootNode->name);

	if(rootNode->rightChild!=NULL)
		inOrderTraversal(rootNode->rightChild);
}

void swapData(HEAP element1, HEAP element2)
{
	HEAP tempNode;
	tempNode=getHeapNode();

	tempNode->priority=element1->priority;
	strcpy(tempNode->name,element1->name);

	element1->priority=element2->priority;
	strcpy(element1->name,element2->name);

	element2->priority=tempNode->priority;
	strcpy(element2->name,tempNode->name);

	return;
}

void heapifyDown(HEAP rootElement)
{
	int max=0;
	if((rootElement->leftChild!=NULL) && (rootElement->rightChild!=NULL))
	{
		if(rootElement->leftChild->priority > rootElement->rightChild->priority)
			max=1; //lChild=1
		else
			max=2; //rChild=2
	}
	else if((rootElement->leftChild!=NULL) && (rootElement->rightChild==NULL))
		max=1; //lChild=1
	else if((rootElement->leftChild==NULL) && (rootElement->rightChild!=NULL))
		max=2; //rChild=2

	if(max==1)
	{
		if(rootElement->priority < rootElement->leftChild->priority)
		{
			swapData(rootElement,rootElement->leftChild);
			heapifyDown(rootElement->leftChild);
		}
		else
			return;
	}
	else if(max==2)
	{
		if(rootElement->priority < rootElement->rightChild->priority)
		{
			swapData(rootElement,rootElement->rightChild);
			heapifyDown(rootElement->rightChild);
		}
		else
			return;
	}
	return;	
}

void heapifyUp(HEAP rootElement)
{
	if((rootElement->parent!=NULL))
	{
		if(rootElement->priority > rootElement->parent->priority)
		{
			swapData(rootElement,rootElement->parent);
			heapifyUp(rootElement->parent);
		}
		else
			return;
	}

	return;	
}

void addElementToHeap(HEAP rootElement, HEAP newElement, int count)
{
	int poppedNumber,pushNumber;
	STACK myStackHead;
	myStackHead=(STACK)malloc(sizeof(struct stack));
	myStackHead->top=getNode();
	myStackHead->top->next=NULL;

	HEAP tempNode;
	tempNode=getHeapNode();
	tempNode=rootElement;
	if(count==1)
	{
		swapData(rootElement,newElement);
	}
	else
	{
		while(count!=0)
		{
			pushNumber=count%2;
			count/=2;
			push(myStackHead,pushNumber);
		}

		poppedNumber=pop(myStackHead);
		if(poppedNumber==-1)
			return;
		while(1)
		{
			poppedNumber=pop(myStackHead);
			if(poppedNumber==-1)
				break;
			else if(poppedNumber==0)
			{
				if(tempNode->leftChild==NULL)
				{
					tempNode->leftChild=newElement;
					newElement->parent=tempNode;
					heapifyUp(newElement);
				}
				else
					tempNode=tempNode->leftChild;
			}
			else if(poppedNumber==1)
			{
				if(tempNode->rightChild==NULL)
				{
					tempNode->rightChild=newElement;
					newElement->parent=tempNode;
					heapifyUp(newElement);
				}
				else
					tempNode=tempNode->rightChild;
			}
		}
	}
	return;
}

