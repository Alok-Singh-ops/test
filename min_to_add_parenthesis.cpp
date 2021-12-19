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


int minAddToMakeValid(string s) {
  int count = 0;
  stack<char> st;
  for (int i = 0; i < s.length(); i++)
  {
    /* code */
    if (s[i] == '(')
    {
      st.push('(');
      count++;
      continue;
    }
    else if (!st.empty() && s[i] == ')')
    {
      st.pop();
      count--;
    }
    else if(st.empty() && s[i] == ')')
    {
      count++;
    }
    
  }
  return count;
  
}

int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//

    std::cout << minAddToMakeValid("()))((") << std::endl;
    
    return 0;
}