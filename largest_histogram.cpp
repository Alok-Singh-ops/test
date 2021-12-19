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


int largestRectangleArea(vector<int>& heights) {
  int ans = 0;
  vector<int> left;
  vector<int> right;
  vector<int> width;


  stack<pair<int,int>> st;
  for (int i = 0; i < heights.size(); i++)
  {
    if (st.empty())
    {
      left.push_back(-1);
    }
    else if (!st.empty() && st.top().first<heights[i])
    {
      left.push_back(st.top().second);
    }
    else if (!st.empty() && st.top().first >=heights[i])
    {
      while (!st.empty()&& st.top().first>=heights[i])
      {
        st.pop();
      }
      if(st.empty())
        left.push_back(-1);
      else
        left.push_back(st.top().second);
    }
    st.push({heights[i],i});
  }
  
  while (!st.empty())
  {
    st.pop();
  }
  

  for (int i = heights.size()-1; i >= 0; i--)
  {
    if (st.empty())
    {
      right.push_back(heights.size());
    }
    else if (!st.empty() && st.top().first<heights[i])
    {
      right.push_back(st.top().second);
    }
    else if (!st.empty() && st.top().first >=heights[i])
    {
      while (!st.empty()&& st.top().first>=heights[i])
      {
        st.pop();
      }
      if(st.empty())
        right.push_back(heights.size());
      else
        right.push_back(st.top().second);
    }
    st.push({heights[i],i});

  }
  reverse(right.begin(),right.end());

  for (int i = 0; i < heights.size(); i++)
  {
    /* code */
    width.push_back(right[i]-left[i]-1);
  }

  for (int i = 0; i < heights.size(); i++)
  {
    /* code */
    ans = max(ans,width[i]*heights[i]);
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
    vector<int> ip = {6,2,5,4,5,1,6};
    // vector<int> ans = largestRectangleArea(ip);
    // for(int i:ans)
    //   std::cout << i << std::endl;
    std::cout << largestRectangleArea(ip) << std::endl;
    
    return 0;
}