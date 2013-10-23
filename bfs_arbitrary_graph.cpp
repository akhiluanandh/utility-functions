#include <vector>
#include <queue>
#define for_each(it, container) \
  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define MAXV 1000
#define INF 10000000

using namespace std;

vector< vector<int> > graph;
int depth[MAXV+1];
bool completed[MAXV+1];

void bfs(int source, int n)
{
  for(int i = 0; i < n; i++)
    depth[i] = INF;
  depth[source] = 0;
  queue<int> Q;
  Q.push(source);
  completed[source] = true;
  while(!Q.empty())
  {
    int temp = Q.front();
    Q.pop();
    for_each(vertex, graph[temp])
    {
      if(!completed[*vertex])
      {
        depth[*vertex] = depth[temp] + 1;
        completed[*vertex] = true;
        Q.push(*vertex);
      }
    }
  }
}

int main()
{
  return 0;  
}
