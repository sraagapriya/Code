/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

int main()
{
	int nc;

	nc=0;
	while (getchar() != EOF)
		++nc;

	printf("%d\n",nc);

	return 0;
}