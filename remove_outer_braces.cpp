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

string removeOuterParentheses(string s) {
  string op;
  stack<char> st;

  
for(char it: s){
  
  if (it == '(')
  {
    st.push('(');
    continue;
  }

  if (it == ')')
  {
    op.push_back(st.top());
    st.pop();
    op.push_back(')');
  }
}
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
  //  std::cout << removeOuterParentheses("(()())(())") << std::endl;
  signed char a = -46;
  std::cout << a << std::endl;
    return 0;
}