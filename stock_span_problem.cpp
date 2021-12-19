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


vector <int> calculateSpan(int price[], int n)
{
  vector<int> op;
  stack<pair<int,int>> st;
  for (int i = 0; i < n; i++)
  {
    if (st.empty())
    {
      op.push_back(-1);
    }
    else if (!st.empty()&& st.top().first > price[i])
    {
      op.push_back(st.top().second);
    }
    else if (!st.empty() && st.top().first<=price[i])
    {
        while (!st.empty()&&st.top().first<=price[i])
        {
          st.pop();
        }
        if(st.empty())
          op.push_back(-1);
        else
          op.push_back(st.top().second);
      }
      st.push({price[i],i});
  }
  // for (int i = 0; i < op.size(); i++)
  // {
  //   /* code */
  //   op[i] = i-op[i];
  // }
  
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
  
  int ip[10] = {73,74,75,71,69,72,76,73};
    vector<int> ans = calculateSpan(ip,8);
    for(int i:ans)
      std::cout << i << std::endl;
    return 0;
}