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


string removeDuplicates(string s) {
    string op;
    stack<char> st;
    for(int i = 0;i<s.length();i++){
      if (st.empty())
        st.push(s[i]);
      else if (s[i] != st.top())
      {
        /* code */
      st.push(s[i]);
      continue;
      }
      else
      st.pop();
        // std::cout << st.top() <<" Inside if" << std::endl;
    }
    
    while (!st.empty())
    {
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
      // freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//

    std::cout << removeDuplicates("abbaca") << std::endl;
    
    return 0;
}