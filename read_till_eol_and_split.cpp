#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(string a)
{
  int n = a.size(), count = 0, i;
  char prev = '.';
  vector<string> ans;
  string emptystring;
  if(n == 0)
    return ans;
  ans.push_back(emptystring);
  for(i = 0; i < n; i++)
  {
    if(a[i] == ' ')
    {
      if(prev != ' ')
      {
        count++;
        prev = ' ';
        ans.push_back(emptystring);
      }
    }
    else
    {
      ans[count].push_back(a[i]);
      prev = '.';
    }
  }
  if(ans[count].size() == 0)
    ans.erase(ans.begin() + count);
  return ans;
}

int main()
{
  int t;
  ios_base::sync_with_stdio(false);
	string line;
  vector<string> words;
  cin>>t;
	getline(cin, line);
  while(t--)
  {
    getline(cin, line);
    words = split(line);
  }
  return 0;
}
