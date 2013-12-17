#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100000

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

vector<iii> edges;

struct NODE
{
  NODE *h;  
} head[MAX];

bool comp(iii a, iii b)
{
  return a.second < b.second;  
}

int main()
{
  ios_base::sync_with_stdio(false);
  int n, a, b, c, m;
  cin>>n;
  cin>>m;
  for(int i = 0; i < m; i++)
  {
    cin>>a;
    cin>>b;
    cin>>c;
    head[a].h = &head[a];
    head[b].h = &head[b];
    edges.push_back(iii(ii(a, b), c));
  }
  sort(edges.begin(), edges.end(), comp);
  int count = 0, total = 0, added = 0;
  while(added < n-1 && count < edges.size())
  {
    iii temp = edges[count];
    ii edge = temp.first;
    int u = edge.first, v = edge.second;
    int cost = temp.second;
    count++;
    while(head[u].h->h != head[u].h) head[u].h = head[u].h->h;
    while(head[v].h->h != head[v].h) head[v].h = head[v].h->h;
    if(head[u].h == head[v].h)
      continue;
    head[v].h->h = head[u].h;
    added++;
    total += cost;
  }
  cout<<total<<"\n";
  return 0;
}
