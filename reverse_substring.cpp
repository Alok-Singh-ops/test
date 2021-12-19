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

string reverseParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i+1);
            }
            else if(s[i]==')'){
                int x=st.top();
                reverse(s.begin()+x,s.begin()+i);
                std::cout << s << std::endl;
                st.pop();
            }
        }
        string op="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='('&&s[i]!=')')
                op+=s[i];
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
    

// std::cout << reverseParentheses("(ed(et(oc))el)") << std::endl;
string ip = "oc)";
reverse(ip.begin(),ip.begin()+2);
std::cout << ip << std::endl;
    return 0;
}