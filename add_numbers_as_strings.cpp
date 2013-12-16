#include <iostream>
#include <string>

using namespace std;

int getint(char a)
{
  return a-48;  
}

char getc(int a)
{
  return a+48;  
}

string reverse(string a)
{
  return string(a.rbegin(), a.rend());  
}

string add(string a, string b)
{
  string answer;
  int carry = 0, temp;
  string::reverse_iterator itb = b.rbegin(), ita = a.rbegin();
  for(; itb != b.rend() && ita != a.rend(); itb++, ita++)
  {
    temp = (getint(*itb) + getint(*ita) + carry);
    if(temp >= 10)
    {
      answer.push_back(getc(temp-10));
      carry = 1;
    }
    else
    {
      answer.push_back(getc(temp));
      carry = 0;
    }
  }
  string::reverse_iterator it;
  int whichone = 0;
  if(itb != b.rend() && (whichone = 2))
    it = itb;
  else if(ita != a.rend() && (whichone = 1))
    it = ita;
  if(whichone)
  {
    string notover = (whichone == 1)?a:b;
    for(;it != notover.rend(); itb++)
    {
      if(carry > 0)
      {
        if(*it > 8)
          answer.push_back(getc(getint(*it)+carry-10));
        else
        {
          answer.push_back(getc(getint(*it)+carry));
          carry = 0;
        }
      }
    }
  }
  if(carry)
    answer.push_back(getc(carry));
  answer = reverse(answer);
  return answer;
}

int main()
{
  int t, n;
  long long k;
  string sn, sk;
  cin>>t;
  while(t--)
  {
    cin>>sn;
    cin>>sk;
    cout<<add(sn, sk)<<"\n";
  }
  return 0;
}
