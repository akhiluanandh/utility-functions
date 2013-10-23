#include <vector>

#define for_each(it, container) \
  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define MAXV 1000

using namespace std;

vector< vector<int> > graph;
bool completed[MAXV+1];

void dfs(int i)
{
  completed[i] = true;
  for_each(vertex, graph[i])
    if(!completed[*vertex])
      dfs(*vertex);
}

int main()
{
  return 0;  
}
