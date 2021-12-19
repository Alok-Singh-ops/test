#include<iostream>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cctype>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

#define ll long long
#define mod 1e9+7


bool isValid(string ip){
  stack<char> s;
  char x;

  for (int i = 0; i < ip.length(); i++)
  {
    if (ip[i] == '('||ip[i] == '{'||ip[i] == '[')
    {
      s.push(ip[i]);
      continue;
    }
    if(s.empty())
      return false;

    switch (ip[i])
    {
    case ')':
      x = s.top();
      s.pop();
      if (x == '['||x == '{')
      return false;
      break;

      case '}':
      x = s.top();
      s.pop();
      if (x == '('||x == '[')
        return false;
      break;
    
    case ']':
      x = s.top();
      s.pop();
      if (x == '('||x == '{')
        return false;
      break;
    }
  }
  return s.empty();
}



int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//
    string ip = "({{{{}}}))";
    
    if (isValid(ip))
      std::cout << "Balanced" << std::endl;
    else
    {
      std::cout << "Not Balanced" << std::endl;
    }
  

    return 0;
} 