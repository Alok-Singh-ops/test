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

int calPoints(vector<string>& ops) {
stack<int> st;
int ans = 0;
    for (int i = 0; i < ops.size(); i++)
    {
      string p = ops[i];
      char q = p[0];
      if (q>=48 && q<=57 )
      {
        st.push(q-48);
        // std::cout << st.top() << std::endl;
        continue;
      }
      
      else if (stoi(p)<0)
      {
        std::cout << stoi(p) << std::endl;
        st.push(stoi(p));
      }
      // std::cout << q << std::endl;
      // switch (q)
      // {
      // case 'C':
      //   st.pop();
      //   break;
      //   case 'D':
      //   st.push(2*st.top());
      //   break;
      //   case '+':
      //   int x = st.top();

      //   st.pop();
      //   int y = st.top();

      //   st.push(x);
      //   st.push(x+y);
      //   break;
      // }
    }
    while (!st.empty())
    {
      /* code */
      std::cout << st.top() << std::endl;
      ans += st.top();
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
    vector<string> ip = {"5","-2","4","C","D","9","+","+"};
    int ans = calPoints(ip);
    // std::cout << ans << std::endl;
    return 0;
}