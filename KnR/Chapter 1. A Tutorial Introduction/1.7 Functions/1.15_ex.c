/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float toCelcius(float );

int main()
{
	float fahr;

	for(fahr=LOWER;fahr<=UPPER;fahr+=STEP)
		printf("%3.0f\t%6.1f\n",fahr,toCelcius(fahr));

	return 0;
}

float toCelcius(float fahr)
{
	return (5.0/9.0)*(fahr-32);
}
