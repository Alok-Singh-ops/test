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
int minOperations(vector<string>& logs) {
  int count = 0;
  stack<string> st;
  for (int i = 0; i < logs.size(); i++)
  {
    if (logs[i] == "../")
    {
      if (st.empty())
      continue;
      st.pop();
    }
    else if (logs[i] == "./")
    {
      continue;
    }
    else
    {
      st.push(logs[i]);
    }
  }
  while (!st.empty())
  {
    /* code */
    count++;
    st.pop();
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
    vector<string> ip = {"d1/","../","../","../"};
    cout << minOperations(ip);
    return 0;
}