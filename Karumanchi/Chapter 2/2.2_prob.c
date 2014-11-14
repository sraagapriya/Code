/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

#define NUM 4

void binary(int , char [] );

int main()
{
	char A[NUM+1];
	A[NUM]='\0';

	binary(NUM,A);

	return 0;
}

void binary (int n, char A[])
{
	if (n<1)
		printf("%s\n",A);
	else
	{
		A[n-1]='0';
		binary(n-1,A);
		A[n-1]='1';
		binary(n-1,A);
	}

	return;		
}
