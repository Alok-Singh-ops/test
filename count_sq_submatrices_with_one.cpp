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

int countSquares(vector<vector<int>>& matrix) {
	int row = matrix.size();
	int col = matrix[0].size();
	for(int i = 1; i < row; i++)
		for(int j = 1; j < col; j++)
			if(matrix[i][j])
				matrix[i][j] += min(matrix[i][j-1], min(matrix[i-1][j], matrix[i-1][j-1]));
	int result = 0;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			result += matrix[i][j];
	return result;
}


int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//
    
    vector<vector<int> > ip = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    int m = ip.size();
    int n = ip[0].size();
    vector<vector<int> > op(m,vector<int> (n,0));



    for (int i = 0; i<n; i++)
      op[0][i] = ip[0][i];
    
    for (int i = 0; i < m; i++)
      op[i][0] = ip[i][0];

    

    // for (int i = 0; i < ip.size(); i++)
    // {
    //   /* code */
    //   for (int j = 0; j < ip[0].size(); j++)
    //   {
    //     std::cout << op[i][j] << " ";
    //   }
    //   std::cout << std::endl;
    // }

    cout << countSquares(ip);
    
    
    
    return 0;
}