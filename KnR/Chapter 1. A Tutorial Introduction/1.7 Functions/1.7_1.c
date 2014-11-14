/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

int power(int ,int );

int main()
{
	int i;

	for(i=0;i<10;++i)
		printf("%d %3d %6d\n",i,power(2,i),power(-3,i));

	return 0;
}

int power(int base, int n)
{
	int i,p;

	p=1;
	for(i=0;i<n;++i)
		p *= base;

	return p;
}
