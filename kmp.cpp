#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
void getTable(string s,int* table)
{
	int len = s.size();
	table[0] = 0;
	for(int i=1;i<len;)
	{
		while(s[i]!=s[0] && i<len)
		{	
			table[i]=0;
			i++;
		}
		
		if(i<len)
		{	
			table[i]=1;
			i++;
			int matched=1;
			while(s[matched]==s[i] && i<len)
			{
				matched++;
				table[i] = matched;
				i++;
			}

		}
	}
}
int main()
{	
	
		
		string text,pattern;
		cin>>pattern;
		cin>>text;
		int len = pattern.size();
		int table[len];
		getTable(pattern,table);
		for(int i=0;i<text.size();i++)
		{
			int j=0;
			int start = i;
			while(pattern[j]==text[i] && i<text.size() && j<len)
				{
					i++;j++;
				}
			if(j==len)
				{
					printf("%d\n",start);
				}
			i = start;
			if(j>=1)
				{
					i+=(j-table[j-1])-1;
				}
		}	
	
	return 0;

}
