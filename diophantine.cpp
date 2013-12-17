#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm> // binsearch
#include <math.h> 
#include <vector>
#include <set>
#include <map> 
#include <string.h> // memset
#include <cstdlib> // abs(int),labs(int),llabs(int),min,max
#include <limits.h> // int_max,int_min,long_long_max,long_long_min
#include <tr1/unordered_map>
#include <functional> // for the default  hash functions. There exists a class Hash inside it. 
using namespace std;

#define read(x) cin>>x 
#define EPS 0.0000001


typedef long long LL;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
vector<int> diophantiine(int a,int b)
{	int c = gcd(a,b);
	bool swapped = false;
	int xCurrent,yCurrent;
	if(a>b)
	{	
		int temp = a;
		a = b;
		b = temp;
		swapped  = true;
	}
	int xPrev = 0,yPrev = 1;
	int cPrev= b;
	xCurrent = 1; 
	yCurrent = 0;
	int cCurrent = a;  
	while(cCurrent!=c)
	{	
		int temp = cCurrent;
		int factor;
		factor = cPrev/cCurrent;
		cCurrent = cPrev%cCurrent;
		int tempX = xCurrent,tempY = yCurrent;
		xCurrent = xPrev - factor*(xCurrent);
		yCurrent = yPrev - factor*(yCurrent);
		cCurrent = xCurrent*a + yCurrent*b;
		xPrev = tempX;
		yPrev = tempY;
		cPrev = temp;
	}
	vector<int> ret;
	ret.push_back(xCurrent);
	ret.push_back(yCurrent);
	if(swapped) 
	{
	 return vector<int>(ret.rbegin(),ret.rend());
	}
	return ret;

}
int main()
{	int a,b;
	scanf("%d %d",&a,&b);
	vector<int> test = diophantiine(a,b);
	for(int i=0;i<test.size();i++) printf("%d\t",test[i]);
	return 0;
}
