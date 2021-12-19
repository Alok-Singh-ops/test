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

int highPrecedence(char c){
  if (c == '^')
  {
    /* code */
    return 3;
  }
  else if (c == '*' || c == '/')
  {
    return 2;
  }
  else if(c == '+' || c == '-')
  {
    return 1;
  }
  
  return -1;
}



int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//
    string ip = "1+(2*3)-10";
    string op;
    stack<char> s;
    for (int i = 0; i < ip.length(); i++)
    {
      /* code */
      //check if ip[i] is operand
      if ((ip[i]>='a'&&ip[i]<='z')||ip[i]>='A'&&ip[i]<='Z'||ip[i]>='0'&&ip[i]<='9')
      {
        /* code */
        op.push_back(ip[i]);
        continue;
      }
      else
      {
        //if we encounter a opening braces push it in the stack
        if (ip[i] == '(')
        {
          s.push('(');
          continue;
        }
        //if we encounter a closing braces then traverse the stack until we get opening braces and push all the elements in the op string
        else if (ip[i] == ')')
        {
          while (s.top()!='(')
          {
            op.push_back(s.top());
            s.pop();
          }
          //pop the last element in the stack -- '('
          s.pop();
        }
        else
        {
          //if none of the above then it must be operator. check if the stack is empty and check for the precedence of operator in the stack and in the string. if stack precedence if higher then the string then pop if from the stack and push it in op string
          while (!s.empty() && highPrecedence(ip[i]) <= highPrecedence(s.top()))
          {
            op.push_back(s.top());
            s.pop();
          }
          s.push(ip[i]);
        }
      }
      //push the remianing element in the stack
      
      
    }
    while (!s.empty())
      {
        /* code */
        op.push_back(s.top());
        s.pop();
      }
    
    std::cout << op << std::endl;
    
    return 0;
}