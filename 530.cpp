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

#define ll long long
#define mod 1e9+7

struct TreeNode
{
int val;
struct TreeNode *left, *right;
TreeNode(int data){
this->val = data;
this->left = NULL;
this->right = NULL;
}
};


int minDifference(vector<int> ip){
  int diff = INT_MAX;
  sort(ip.begin(),ip.end());
  for (int i = 0; i < ip.size()-1; i++)
  {
    if (ip[i+1]-ip[i] < diff)
      diff = ip[i+1]-ip[i];
    
  }
  return diff;
}

void preOrder(TreeNode *root,vector<int> &temp){
  if (!root)
    return;
  temp.push_back(root->val);
  preOrder(root->left,temp);
  preOrder(root->right,temp);
}

int getMinimumDifference(TreeNode* root) {
  vector<int> temp;
  preOrder(root,temp);

  return minDifference(temp);
}

int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    std::cout << getMinimumDifference(root) << std::endl;
    return 0;
}