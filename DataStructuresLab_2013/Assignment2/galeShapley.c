/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2013
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>

//Used to get preference list of men and women
void getPreferenceList(int number, int** menPreferenceList, int** womenPreferenceList)
{
	int i,j;
	for (i=0; i<number; i++)
	{
		printf("\nEnter preference list of Man %d:\n",i+1);
		for (j=0; j<number; j++)
			scanf("%d",&menPreferenceList[i][j]);
	}

	for (i=0; i<number; i++)
	{
		printf("\nEnter preference list of Woman %d:\n",i+1);
		for (j=0; j<number; j++)
			scanf("%d",&womenPreferenceList[i][j]);
	}

	return;
}

//Stores the rank of various men in the oreder of input
void sortWomenPreferenceList(int number, int** womenPreferenceList,int** womenSortedList)
{
	int i,j,preference;
	for(i=0;i<number;i++)
		for (j=0;j<number;j++)
		{
			preference=womenPreferenceList[i][j];
			womenSortedList[i][preference-1]=j+1;
		}
	return;
}

//Implements the Gale Shapley Algorithm
void galeShapley(int number, int** menPreferenceList, int** womenPreferenceList, int* proposalArray)
{
	int **womenSortedList,i,*freeWomanArray,currentMan,currentWoman;

	//Linked list which stores the unpaired men
	struct node{
		int manID;
		struct node *next;
	};

	//Allocates the memory
	womenSortedList = (int**)malloc(number * sizeof(int*));
	for (i = 0; i < number; i++)
		womenSortedList[i]=(int*)malloc( number * sizeof(int));

	sortWomenPreferenceList(number,womenPreferenceList, womenSortedList);
	
	//Stores whether a woman is unpaired or not
	freeWomanArray=(int*)malloc(number*sizeof(int));
	for (i = 0; i < number; i++)
		freeWomanArray[i]=-1;

	struct node *unmatchedMenList;
	struct node *temp, *counter, *lastElement; //lastElement stores the pointer to the last node of the linked list

	//Initialises the head of the linked list with first man
	unmatchedMenList=(struct node*)malloc(sizeof(struct node));
	unmatchedMenList->manID=1;
	unmatchedMenList->next=NULL;

	temp=(struct node*)malloc(sizeof(struct node));
	lastElement=(struct node*)malloc(sizeof(struct node));
	temp=unmatchedMenList;
	lastElement=unmatchedMenList;

	//Initialises the linked list with all unpaired men
	for(i=1; i<number; i++)
	{
		counter=(struct node*)malloc(sizeof(struct node));
		counter->manID=i+1;
		counter->next=NULL;
		lastElement=counter;
		temp->next=counter;
		temp=temp->next;
	}

	temp=unmatchedMenList;
	counter=NULL;
	while(temp!=NULL)	
	{
		currentMan=(temp->manID)-1; //currentMan contains values 0,1,2,3
	
		//iterates the preferences of a man
		for(i=proposalArray[currentMan];i<number;i++)
		{
			currentWoman=(menPreferenceList[currentMan][i])-1; //currentWoman contains values 0,1,2
			
			if(freeWomanArray[currentWoman]==-1) //If the woman is free
			{
				freeWomanArray[currentWoman]=currentMan; //pairs the woman with the man
				if(unmatchedMenList->next!=NULL) //if not the last element remove from the head of the list.
				{
					unmatchedMenList->manID=unmatchedMenList->next->manID; //copy the date of next node to current node
					counter=unmatchedMenList->next; 
					unmatchedMenList->next=counter->next;
					free(counter);
					counter=NULL; //delete the next node as data is copied into current
					if(unmatchedMenList->next==NULL) //assigns the last element
						lastElement=unmatchedMenList;
				}
				else //if the last element, make the temp as null for while to terminate
				{
					temp=temp->next;
				}
				break;
			}
			else
			{
				//If current man is preferred by the woman than already paired man
				if(womenSortedList[currentWoman][currentMan]<womenSortedList[currentWoman][freeWomanArray[currentWoman]])
				{
					//Add a node to the end of linked list for man being unpaired
					counter=(struct node*)malloc(sizeof(struct node));
					counter->manID=freeWomanArray[currentWoman]+1;
					counter->next=NULL;
				
					//new node will be the last node
					lastElement->next=counter;
					lastElement=counter;

					freeWomanArray[currentWoman]=currentMan;

					unmatchedMenList->manID=unmatchedMenList->next->manID;
					counter=unmatchedMenList->next;
					unmatchedMenList->next=counter->next;
					free(counter);
					counter=NULL;

					break;
				}
				else
					proposalArray[currentMan]++; //propose the next woman
			}
		}

	}

	//free the allocated memory
	for (i = 0; i < number; i++) {
  		free(womenSortedList[i]);
		womenSortedList[i]=NULL;
	}
	free(womenSortedList);
	womenSortedList=NULL;

	return;
}

int main()
{
	int i,number, **menPreferenceList, **womenPreferenceList,*proposalArray;

	//Get the number of men and women involved in pairing
	printf("Enter number of men and women: ");
	scanf("%d",&number);
	
	//Allocates memory for data structures dynamically
	menPreferenceList = (int**)malloc(number * sizeof(int*));
	for (i = 0; i < number; i++)
		menPreferenceList[i]=(int*)malloc( number * sizeof(int));

	womenPreferenceList = (int**)malloc(number * sizeof(int*));
	for (i = 0; i < number; i++)
		womenPreferenceList[i]=(int*)malloc( number * sizeof(int));

	proposalArray=(int*)malloc(number*sizeof(int));
	for (i = 0; i < number; i++)
		proposalArray[i]=0;


	getPreferenceList (number, menPreferenceList, womenPreferenceList);
	galeShapley(number, menPreferenceList, womenPreferenceList,proposalArray);

	//Output is generated
	printf("\n\nFinal set of pairs are:");
	for (i=0; i<number; i++)
		printf("\n(m%d,w%d)",i+1,menPreferenceList[i][proposalArray[i]]);
	printf("\n\n");

	//Free the dynamically allocated memory
	free(proposalArray);
	proposalArray=NULL;

	for (i = 0; i < number; i++) {
  		free(menPreferenceList[i]);
		menPreferenceList[i]=NULL;
	}
	free(menPreferenceList);
	menPreferenceList=NULL;

	for (i = 0; i < number; i++) {
  		free(womenPreferenceList[i]);
		womenPreferenceList[i]=NULL;
	}
	free(womenPreferenceList);
	womenPreferenceList=NULL;

	return 0;	
}
