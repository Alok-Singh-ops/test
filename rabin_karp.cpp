#include <iostream>
#include<string>
#include<algorithm>
#include<cmath>



using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define mod 1e9+7


void getPat(string txt,string pat,int q){
  int m = pat.length();
  int n = txt.length();
  int p = 0;
  int t = 0;
  int h = 1;
  int d = 256;
  for (int i = 0; i < m-1; i++)
    h = (h*d)%q;
  
  for (int i = 0; i < m; i++)
  {
    /* code */
    p = ((d*p) + pat[i])%q;
    t = ((t*d)+txt[i])%q;
  }
  
  


}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif //

  string text = "This is text file";
  string pat = "text";
  int q = 101;
  getPat(text,pat,q);

  return 0;
}