#include <cstdio>
#include <vector>
#include <algorithm>
#define gc getchar_unlocked
#define MAX 10000
#define traverse(container, it) \
  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

using namespace std;

int t = 0;
int dis[MAX+1], low[MAX+1], parent[MAX+1];
bool visited[MAX+1], ap[MAX+1];
int apcount;
vector<int> adj[MAX+1];

void get_int(int &p)
{
  int c;
  do
  {
    c = gc();  
  } while(c < 48 || c > 57);
  int x = 0;
  while(c >= 48 && c <= 57)
  {
    x = (x<<1) + (x<<3) + c-48;
    c = gc();
  }
  p = x;
}

void articulation(int u)
{
  int children = 0;
  visited[u] = true;
  dis[u] = low[u] = ++t;
  traverse(adj[u], w)
  {
    int v = *w;
    if(!visited[v])
    {
      children++;
      parent[v] = u;
      articulation(v);
      low[u] = min(low[u], low[v]);

      if(parent[u] == -1 && children > 1)
        ap[u] = true;  
      if(parent[u] != -1 && low[v] >= dis[u])
        ap[u] = true;
    }
    else if(v != parent[u])
      low[u] = min(low[u], dis[v]);
  }
}

int main()
{
  int n, m, a, b;
  do
  {
    get_int(n);
    get_int(m);
    apcount = 0;
    t = 0;
    if(n == 0 && m == 0)
      break;
    for(int i = 0; i <= n; i++)
    {
      adj[i].clear();
      low[i] = dis[i] = 0;
      parent[i] = -1;
      ap[i] = false;
      visited[i] = false;
    }
    for(int i = 0; i < m; i++)
    {
      get_int(a);
      get_int(b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
      if(!visited[i])
        articulation(i);
    for(int i = 1; i <= n; i++)
      if(ap[i])
        apcount++;
    printf("%d\n", apcount);
  } while(true);
  return 0;  
}
