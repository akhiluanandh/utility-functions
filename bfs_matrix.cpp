#include <queue>
#include <cstdio>

using namespace std;

#define ROWSIZE 100
#define COLUMNSIZE 100
#define INF 1000000000

typedef pair<int, int> ii;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

bool exists(int i, int j, int m, int n)
{
  if(i >= 0 && i < m && j >= 0 && j < n)
    return true;
  return false;
}

int matrix[ROWSIZE][COLUMNSIZE], depths[ROWSIZE][COLUMNSIZE];
bool completed[ROWSIZE][COLUMNSIZE];

bool condition(int i, int j)
{
  /* example:
     if(matrix[i][j] != 9 || matrix[i][j] != 10)
      return false;
     return true;
   */
  return true;
}

void bfs(int sourcei, int sourcej, int m, int n)
{
  queue<ii> Q;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      depths[i][j] = INF;
  Q.push(ii(sourcei, sourcej));
  depths[sourcei][sourcej] = 0;
  completed[sourcei][sourcej] = true;
  while(!Q.empty())
  {
    ii temp = Q.front();
    Q.pop();
    int i = temp.first, j = temp.second, newi, newj;
    for(int k = 0; k < 4; k++)
    {
      newi = i+dx[k];
      newj = j+dy[k];
      if(exists(newi, newj, m, n))
      {
        if(!condition)
          continue;
        if(!completed[newi][newj])
        {
          completed[newi][newj] = true;
          depths[newi][newj] = depths[i][j] + 1;
          Q.push(ii(newi, newj));
        }
      }
    }
  }
}

int main()
{
  return 0;  
}
