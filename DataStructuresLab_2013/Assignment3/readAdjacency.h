/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

//Assignment 3

#ifndef TEMP1
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#endif

int getNodeCount(char *inputFile) //Returns the number of vertex
{
	FILE *fp;
	char str[10];
	int count=0;
	if ((fp=fopen(inputFile,"r"))==NULL)
	{
		printf("\nError opening file\n");
		exit(-1);
	}
	while((fgets(str,9,fp))!=NULL)
		count++;
	fclose(fp);
	
	return count-1;
}

LINKED_LIST* readAdjacencyList(char *inputFile,LINKED_LIST *vertex,int count)
//Reads the adjacency list
{
	char temp[5]; //Can accomodate graph with 9999 nodes
	int x,i=0,num;
	LINKED_LIST lastNode;
	int newList=0,listNumber;

	FILE *fp2;
	if((fp2=fopen(inputFile,"r"))==NULL)
	{
		printf("\nError Opening File");
		exit(-1);
	}

	vertex=(LINKED_LIST*)malloc(count*sizeof(LINKED_LIST)); //Allocates the memory to pointer array storing the adjacency list

	int k;
	for(k=0;k<count;k++) //Allocates memory to each list corresponding to a single vertex
	{
		vertex[k]=getNode();
		vertex[k]->next=NULL;
	}

	while((x=(fgetc(fp2)))!=EOF) //Reads the file character by character
	{
		if(x!=' ' || x!='\n') //If no space then its a number
			temp[i++]=x;
			
		if(newList==0 && x==' ') //For the first entry in each row, its representing the vertex
		{
			temp[i]='\0';
			num=atoi(temp);	
			listNumber=num-1; 
			lastNode=vertex[listNumber]; //store the list in corresponding position in array
			i=num=0;
			newList++;
		}
		else if(newList==1)
			newList++;
		else if(newList>=1 && (x==' ' || x=='\n')) //Builds the list
		{
			temp[i]='\0';
			num=atoi(temp);	

			LINKED_LIST tempNode; //Create a new node when space encountered
			tempNode=getNode();
			tempNode->key=num;
			tempNode->next=NULL;
			lastNode->next=tempNode;
			lastNode=tempNode;
			i=0;
			newList++;
		}	
		
		if(x=='\n') //If newline then new vertex's list will come
			newList=0;
		
	}
	fclose(fp2);

	return vertex;	

}

void printList(LINKED_LIST head) //Prints the linked list in adjacency list pattern
{
	if(isListEmpty(head))
		return;
	else{
	LINKED_LIST tempNode=getNode();
	tempNode=head->next;	
	while(tempNode != NULL)
	{
		printf("->%d",tempNode->key);
		tempNode=tempNode->next;
	}
	printf("\n\n");
	}
	return;
}

void printAdjacencyList(LINKED_LIST *vertex, int count) //Calls the print function for each list in array of adjacency list
{
	int k;
	printf("\nAdjacency List:\n");
	for (k=0;k<count;k++)
	{
		printf("%d",k+1);		
		printList(vertex[k]);
	}
}


