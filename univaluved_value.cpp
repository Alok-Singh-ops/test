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
  int val;
  TreeNode *left,*right;
  TreeNode(int val){
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

  void levelOrder(TreeNode *root){
    if (root == NULL)
      return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *node = q.front();
      std::cout << node->val << std::endl;
      q.pop();
      if (node->left != NULL)
        q.push(node->left);
      if (node->right != NULL)
        q.push(node->right);
    }
  }

bool helper(TreeNode *root,int value){
  if (root == NULL)
    return true;
  if (root->val != value)
    return false;
  
  return helper(root->left,value) & helper(root->right,value);
}

  bool isUnivalTree(TreeNode* root) {
    return helper(root,root->val);
  }


int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(1);


  std::cout << isUnivalTree(root) << std::endl;


    
    return 0;
}