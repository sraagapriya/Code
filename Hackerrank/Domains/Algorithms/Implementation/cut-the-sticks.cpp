/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 **********************************************************/
 
/*
https://www.hackerrank.com/challenges/cut-the-sticks

You are given N sticks, where each stick is of positive integral length. A cut operation is performed on the sticks such that all of them are reduced by the length of the smallest stick.

Suppose we have 6 sticks of length

5 4 4 2 2 8

then in one cut operation we make a cut of length 2 from each of the 6 sticks. For next cut operation 4 sticks are left (of non-zero length), whose length are

3 2 2 6

Above step is repeated till no sticks are left.

Given length of N sticks, print the number of sticks that are cut in subsequent cut operations.

Input Format
The first line contains a single integer N.
The next line contains N integers: a0, a1,...aN-1 separated by space, where ai represents the length of ith stick.

Output Format
For each operation, print the number of sticks that are cut in separate line.

Constraints
1 ≤ N ≤ 1000
1 ≤ ai ≤ 1000

Sample Input #00

6
5 4 4 2 2 8

Sample Output #00

6
4
2
1

Sample Input #01

8
1 2 3 4 3 3 2 1

Sample Output #01

8
6
4
1

Explanation

Sample Case #00 :

sticks-length        length-of-cut   sticks-cut
5 4 4 2 2 8             2               6
3 2 2 _ _ 6             2               4
1 _ _ _ _ 4             1               2
_ _ _ _ _ 3             3               1
_ _ _ _ _ _           DONE            DONE

Sample Case #01

sticks-length         length-of-cut   sticks-cut
1 2 3 4 3 3 2 1         1               8
_ 1 2 3 2 2 1 _         1               6
_ _ 1 2 1 1 _ _         1               4
_ _ _ 1 _ _ _ _         1               1
_ _ _ _ _ _ _ _       DONE            DONE
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int i,j,n,*array,min=1000,allZero=0;
    scanf("%d\n",&n);
    
    array=(int*)malloc(sizeof(int)*n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d ",&array[i]);
        if(array[i]<min)
            min=array[i];
    }
    
    while(!allZero)
    {
        int prev,cutCount=0,newMin=1000;
        for(i=0;i<n;i++)
        {
            prev=array[i];
            if(prev>0 && prev>min)
                array[i]-=min;
            else if(prev>0 && prev<=min)
                array[i]=0;
            
            if(prev!=0)
                cutCount++;
                
            if(array[i]!=0 && array[i]<newMin)
                newMin=array[i];
        }
        printf("%d\n",cutCount);
        min=newMin;
        
        for(i=0;i<n;i++)
            if(array[i]!=0)
                break;

        if(i==n)
            allZero=1;
    }
    
    free(array);
    return 0;
}

