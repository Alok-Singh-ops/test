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


vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
    vector<long long> op;

    stack<long long> st;
    for (int i = n-1; i >= 0; i--)
    {

      if (st.empty())
        op.push_back(-1);
      else if (st.top()>arr[i] && !st.empty())
      {
        op.push_back(st.top()); 
      }
      else if (!st.empty() && st.top()<arr[i])
      {
        while (!st.empty()&&st.top()<=arr[i])
        {
          st.pop();
        }
        if(st.empty())
          op.push_back(-1);
        else
          op.push_back(st.top());
      }

      st.push(arr[i]);
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
    // vector<long long> nums1 = {1,3,2,4};
    // vector<long long> op = nextLargerElement(nums1,4);
    // for(int i:op)
    //   std::cout << i << std::endl;
    string ip = "-2";
    std::cout << stoi(ip) << std::endl;
    
    return 0;
}