/*
AUTHOR: Akhilesh Anandh
Function for reading signed/unsigned integers from stdin
*/
#include<stdio.h>
int read_int(){
	register int x=0,sign=1,c;
	do
	{
		c = getchar_unlocked();
	}while( (c<'0' || c>'9')&&c!='-');
	if(c=='-')
	{
		sign=-1;
		c = getchar_unlocked();
	}
	while(c>='0'&&c<='9')
	{
		x = x*10 + c - '0';
		c = getchar_unlocked();
	}
	return sign*x;
}

