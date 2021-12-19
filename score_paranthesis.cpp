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


int scoreOfParentheses(string s) {
  stack<int> st;
  int ans = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '(')
    {
      /* code */
      st.push(-1);
      // std::cout << st.top() << std::endl;
    }
    else
    {
      if (st.top() == -1)
      {
        st.pop();
        st.push(1);
        // std::cout << st.top() << std::endl;
      }
      else
      {
    int val = 0;
        while (st.top()!=-1)
        {
          val += st.top();
          st.pop();
        }
        st.pop();
        st.push(2*val);
      }
    }
  }
  while (!st.empty())
  {
    ans+=st.top();
    st.pop();
  }
  return ans;
}


int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//
    
    std::cout << scoreOfParentheses("()()") << std::endl;
    return 0;
}