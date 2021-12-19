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

struct TreeNode
{
  /* data */
  int val;
  struct TreeNode *left, *right;
  TreeNode(int data){
    this->val = data;
    this->left = NULL;
    this->right = NULL;
  };
};


void helper(TreeNode *root,vector<int> &ans){
  if (root == NULL)
    return;
    ans.push_back(root->val);
    helper(root->left,ans);
    helper(root->right,ans);
  
}

vector<int> preorderTraversal(TreeNode* root) {
  vector<int> ans;
  helper(root,ans);
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
    return 0;
}