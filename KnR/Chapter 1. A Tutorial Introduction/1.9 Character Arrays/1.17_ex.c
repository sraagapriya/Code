/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
#include <stdio.h>

#define MAXLINE 1000
#define MINLIMIT 80
//Newline character at the end of each line is included in these limits.

int getLine(char [] , int );

int main()
{
	int len;
	char line[MAXLINE];	
	
	len=0;
	while( (len = getLine(line,MAXLINE)) > 0 )
		if(len>=MINLIMIT)
			printf("%s\n",line);

	return 0;
}

int getLine (char s[], int lim)
{
	int c,i;

	for(i=0;i<lim-1 && (c=getchar())!= EOF && c!='\n'; ++i)
		s[i]=c;

	if(c=='\n')
	{
		s[i]=c;
		++i;
	}
	
	s[i]='\0';

	return i;	
}
