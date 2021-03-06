/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "minHeap.h"

#define TRUE 1
#define FALSE 0


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

	if(rootNode->rightChild!=NULL)
		inOrderTraversal(rootNode->rightChild);
}

void swapData(HEAP element1, HEAP element2,int* locationVector)
{
	HEAP tempNode;
	tempNode=getHeapNode();
	int tempLoc;
	tempLoc=locationVector[(element1->keyId)-1];
	tempNode->priority=element1->priority;
	tempNode->keyId=element1->keyId;

	locationVector[(element1->keyId)-1]=locationVector[(element2->keyId)-1];
	element1->priority=element2->priority;
	element1->keyId=element2->keyId;

	locationVector[(element2->keyId)-1]=tempLoc;
	element2->priority=tempNode->priority;
	element2->keyId=tempNode->keyId;
	



	return;
}

void heapifyDown(HEAP rootElement,int* locationVector)
{
	int min=0;
	if((rootElement->leftChild!=NULL) && (rootElement->rightChild!=NULL))
	{
		if(rootElement->leftChild->priority < rootElement->rightChild->priority)
			min=1; //lChild=1
		else
			min=2; //rChild=2
	}
	else if((rootElement->leftChild!=NULL) && (rootElement->rightChild==NULL))
		min=1; //lChild=1
	else if((rootElement->leftChild==NULL) && (rootElement->rightChild!=NULL))
		min=2; //rChild=2

	if(min==1)
	{
		if(rootElement->priority > rootElement->leftChild->priority)
		{



			swapData(rootElement,rootElement->leftChild,locationVector);
			heapifyDown(rootElement->leftChild,locationVector);
		}
		else
			return;
	}
	else if(min==2)
	{
		if(rootElement->priority > rootElement->rightChild->priority)
		{

			swapData(rootElement,rootElement->rightChild,locationVector);
			heapifyDown(rootElement->rightChild,locationVector);
		}
		else
			return;
	}
	return;	
}

void heapifyUp(HEAP rootElement,int* locationVector)
{
	if((rootElement->parent!=NULL))
	{
		if(rootElement->priority < rootElement->parent->priority)
		{

			swapData(rootElement,rootElement->parent,locationVector);


			heapifyUp(rootElement->parent,locationVector);
		}
		else
			return;
	}

	return;	
}

void addElementToHeap(HEAP rootElement, HEAP newElement, int count,int* locationVector)
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
		swapData(rootElement,newElement,locationVector);
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
					heapifyUp(newElement,locationVector);
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
					heapifyUp(newElement,locationVector);
				}
				else
					tempNode=tempNode->rightChild;
			}
		}
	}
	return;
}

void deleteElementFromHeap (HEAP rootElement, int count,int* locationVector)
{
	int poppedNumber,pushNumber; 
	STACK myStackHead; //Stack used to find where to move to trace the element
	myStackHead=(STACK)malloc(sizeof(struct stack));
	myStackHead->top=getNode();
	myStackHead->top->next=NULL;

	HEAP tempNode;
	tempNode=getHeapNode();
	tempNode=rootElement;

	int temp=count;

	while(temp!=0) //Get binary form of count
	{
		pushNumber=temp%2; //Remainder is pused on stack
		temp/=2;
		push(myStackHead,pushNumber);
	}

	poppedNumber=pop(myStackHead); //last number represents the root element so popped out
	if(poppedNumber==-1)
		return;
	while(1)
	{
		poppedNumber=pop(myStackHead); //pop the number on stack

		if(poppedNumber==-1) //If location reached
		{
			swapData(tempNode,rootElement, locationVector); //swap the data to maintain heap property
			locationVector[(rootElement->keyId)-1]=1;
			if(temp==0) //If previous popped number is 0
				tempNode->parent->leftChild=NULL; //set left child to null
			else if(temp==1) //If previous popped number is 1
				tempNode->parent->rightChild=NULL; //set right child to null
			heapifyDown(rootElement,locationVector); //Maintain the heap proiperty
			freeHeapNode(tempNode); //Free the 
			break;
		}			
		else if(poppedNumber==0) //If popped number is 0 then move left
		{
			tempNode=tempNode->leftChild;
			temp=poppedNumber;
		}
		else if(poppedNumber==1) //If popped number is 1 then move right
		{
			tempNode=tempNode->rightChild;
			temp=poppedNumber;
		}
	}
	return;
}


