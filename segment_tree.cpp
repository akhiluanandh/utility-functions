#include <iostream>
#include <algorithm>

#define ARRSIZE 100000
#define TREESIZE 230000
#define INF 100000000
#define LEFT(i)  (i<<1)
#define RIGHT(i) (1+(i<<1))

using namespace std;

int tree[TREESIZE], lazy[TREESIZE];
int arr[ARRSIZE];

void initialize(int node, int start, int end)
{
  if(start == end)
  {
    tree[node] = arr[start];
    //cout<<"Value of node ("<<start<<","<<end<<") is "<<tree[node]<<"\n";
    return;
  }
  int mid = (start+end)>>1;
  initialize(LEFT(node), start, mid);
  initialize(RIGHT(node), mid+1, end);
  tree[node] = max(tree[LEFT(node)], tree[RIGHT(node)]);
}

void propogate(int node, int start, int end)
{
  if(lazy[node] != 0)
    tree[node] += lazy[node];
  if(LEFT(node) < TREESIZE)
    lazy[LEFT(node)] += lazy[node];
  if(RIGHT(node) < TREESIZE)
    lazy[RIGHT(node)] += lazy[node];
  lazy[node] = 0;
}

void update(int node, int start, int end, int a, int b, int val)
{
  propogate(node, start, end);  
  if(b < start || a > end)
    return;
  if(a <= start && b >= end)
  {
    lazy[node] += val;
    propogate(node, start, end);
    return;
  }
  int mid = (start+end)>>1;
  update(LEFT(node), start, mid, a, b, val);
  update(RIGHT(node), mid+1, end, a, b, val);
  tree[node] = max(tree[LEFT(node)], tree[RIGHT(node)]);
}

int query(int node, int start, int end, int a, int b)
{
  //cout<<"At Node ("<<start<<","<<end<<") with value"<<tree[node]<<"\n";
  propogate(node, start, end);
  if(b < start || a > end)
    return -INF;
  if(a <= start && b >= end)
  {
    propogate(node, start, end);  
    return tree[node];
  }
  int mid = (start+end)>>1;
  int a1 = query(LEFT(node), start, mid, a, b);
  int a2 = query(RIGHT(node), mid+1, end, a, b);
  return max(a1, a2);
}

int main()
{
  ios_base::sync_with_stdio(false);
  int n, a, b, c, d;
  cin>>n;
  for(int i = 1; i <= n; i++)
    cin>>arr[i];
  initialize(1, 1, n);
  int t;
  cin>>t;
  while(t--)
  {
    cin>>a;
    cin>>b;
    cin>>c;
    if(a == 1)
    {
      cin>>d;
      update(1, 1, n, b, c, d);
      continue;
    }
    if(a == -1)
      for(int i = 1; i <= n; i++)
        cout<<arr[i]<<" ";
    else
       cout<<query(1, 1, n, b, c)<<"\n";
  }
  return 0;  
}
