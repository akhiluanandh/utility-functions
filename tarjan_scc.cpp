#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MAX 100000
#define traverse(container, it) \
  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int index, dfsnum[MAX], lowlink[MAX];
bool instack[MAX];
vector<int> adj[MAX];
stack<int> S;

void strongconnect(int v)
{
  dfsnum[v] = index;
  lowlink[v] = index++;
  instack[v] = true;
  S.push(v);

  traverse(adj[v], w)
  {
    if(dfsnum[*w] == -1)
    {
      strongconnect(*w);
      lowlink[v] = min(lowlink[v], lowlink[*w]);
    }
    else if(instack[*w])
      lowlink[v] = min(lowlink[v], dfsnum[*w]);
  }
  if(lowlink[v] == dfsnum[v])
  {
    int w;
    do
    {
      w = S.top();
      S.pop();
      instack[w] = false;
      lowlink[w] = lowlink[v];
    } while(w != v && !S.empty());
  }
}

int main()
{
  index = 0;
  for(int i = 0; i < MAX; i++)
    dfsnum[i] = -1;
  for(int i = 0; i < MAX; i++)
      if(dfsnum[i] == -1)
        strongconnect(i);
  return 0;
}
