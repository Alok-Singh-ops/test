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

string makeGood(string s) {
  string op;
  stack<char> st;
  
  for (int i = 0; i < s.length(); i++)
  {
    if (st.empty())
    {
      /* code */
      st.push(s[i]);
      continue;
    }
    std::cout << abs(st.top() - s[i]) << std::endl;
    
    if (abs(st.top() - s[i]) == 32)
    {
      st.pop();
      continue;
    }
    else
      st.push(s[i]);
  }
  while (!st.empty())
  {
    /* code */
    op.push_back(st.top());
    st.pop();
  }
  reverse(op.begin(),op.end());
  return op;
}


int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//
    cout << makeGood("Pp");
    return 0;
}