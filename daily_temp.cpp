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
#include <unordered_map>
using namespace std;

#define ll long long
#define mod 1e9+7

vector<int> dailyTemperatures(vector<int>& temperatures) {
  vector<int> op;
  stack<pair<int,int>> st;
  for (int i = 0; i < temperatures.size(); i++)
  {
    if (st.empty())
    {
      op.push_back(-1);
    }
    else if (!st.empty()&& st.top().first > temperatures[i])
    {
      op.push_back(st.top().second);
    }
    else if (!st.empty() && st.top().first<=temperatures[i])
    {
        while (!st.empty()&&st.top().first<=temperatures[i])
        {
          st.pop();
        }
        if(st.empty())
          op.push_back(-1);
        else
          op.push_back(st.top().second);
      }
      st.push({temperatures[i],i});
  }
  
  

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
    int TC;
    std::cin>> TC;
    while(TC--){
    }
    return 0;
}