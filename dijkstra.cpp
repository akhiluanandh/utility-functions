#include <iostream>
#include <vector>
#include <queue>

#define MAX 10000
#define INF 100000000
#define traverse(container, it) \
  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

using namespace std;

typedef pair<int, int> ii;

int depths[MAX+1];
vector<ii> adj[MAX+1];
bool completed[MAX+1];

struct MinHeap
{
  bool operator()(int a, int b)
  {
    return depths[a] > depths[b];
  }
};

int dijkstra(int source, int dest)
{
  int temp, newv, cost;
  depths[source] = 0;
  priority_queue<int, vector<int>, MinHeap> Q;
  Q.push(source);
  while(!Q.empty())
  {
    temp = Q.top();
    Q.pop();
    if(completed[temp])
      continue;
    completed[temp] = true;
    if(temp == dest)
      return depths[dest];
    traverse(adj[temp], w)
    {
      newv = (*w).first;
      cost = (*w).second;
      if(completed[newv])
        continue;
      if(depths[temp] + cost < depths[newv])
      {
        depths[newv] = depths[temp] + cost;
        Q.push(newv);
      }
    }
  }
  return 0;
}

int main()
{
  int n, m, source, dest, a, b, c;
  cin>>n;
  for(int i = 0; i <= n; i++)
    depths[i] = INF;
  cin>>m;
  for(int i = 0; i < m; i++)
  {
    cin>>a>>b>>c;
    adj[a].push_back(ii(b, c));
    adj[b].push_back(ii(a, c));
  }
  cin>>source>>dest;
  cout<<dijkstra(source, dest)<<"\n";
}
