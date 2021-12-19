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
#include<unordered_map>
using namespace std;

int Knapsack(int wt[], int val[], int W, int n) {
	int t[n + 1][W + 1]; // DP matrix

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0) // base case
				t[i][j] = 0;
			else if (wt[i - 1] <= j) { // current wt can fit in bag
				int val1 = val[i - 1] + t[i - 1][j - wt[i - 1]]; // take current wt
				int val2 = t[i - 1][j]; // skip current wt
				t[i][j] = max(val1, val2);
			}
			else if (wt[i - 1] > j) // current wt doesn't fit in bag
				t[i][j] = t[i - 1][j];
		}
	}
  for (int i = 0; i < n+1; i++)
  {
    for (int j = 0; j < W+1; j++)
    {
      std::cout << t[i][j] << " ";
    }
    std::cout <<std::endl;
  }
  

	return t[n][W];
}

signed main() {
  int n = 5;
  int wt[] = {1,2,5,6,7};
  int val[] = {1,6,18,22,28};
  int W = 10;
	cout << Knapsack(wt, val, W, n) << endl;
	return 0;
}