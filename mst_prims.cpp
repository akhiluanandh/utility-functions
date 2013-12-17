#include<stdio.h>
#include<queue>
using namespace std;
struct Path{
int edgeVal;
int endIndex;
};
struct minHeap
{
    bool operator()(Path a , Path b )
    {
        return a.edgeVal>b.edgeVal;
    }
};
int main()
{	int test;
	
	{
		int junctions,ways;
		scanf("%d %d",&junctions,&ways);
		//printf("%d %d",junctions,ways);
		queue<Path>array[junctions];//adjacency_list
		bool reached[junctions];
		priority_queue<Path,vector<Path>,minHeap> pq ;
		//int totalCost=0;
		for(int i=0;i<ways;i++)
		{	int a1,a2,cost;
			scanf("%d %d %d",&a1,&a2,&cost);
			a1--;
			a2--;
		//	printf("%d %d %lld",a1,a2,costPowe
			Path one,two;
			//totalCost +=cost;
			//printf("%d\n",cost);
			one.edgeVal = cost;
			two.edgeVal = cost;
			one.endIndex = a2;
			two.endIndex = a1;
			//printf("%d %d\n",one.endIndex,one.edgeVal);
			//printf("%d %d\n",two.endIndex,two.edgeVal);
			array[a1].push(one);// making a graph
			array[a2].push(two);
			reached[a1] = reached[a2] = false;
		}
		//printf("total Cost is %d\n",totalCost);
		// start prims algo now
		int counter = 1;
		reached[0]= true;
		int mst = 0;
		int currIndex = 0;	
		while(1)
		{	if(counter >=junctions) break;
			Path temp;
			while(!array[currIndex].empty())
			{
				temp = array[currIndex].front();
				array[currIndex].pop();
				if(!reached[temp.endIndex])
				{
					pq.push(temp);
				}					
			}
			
			Path minimum;
			do{	
				if(pq.empty()) break;	
				minimum = pq.top();
				pq.pop();
			  }while(reached[minimum.endIndex]);
			mst+=minimum.edgeVal;
			currIndex = minimum.endIndex;
			reached[currIndex] = true;
			counter ++ ;
			//printf("Minimum Index is %d and Minimum EdgeVal is%d\n",minimum.endIndex,minimum.edgeVal);
			//printf("MST as of now is %d\n",mst);

		}
		printf("%d\n",mst);
		
	}
	return 0;
}
