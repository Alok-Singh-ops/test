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
  TreeNode* left,*right;
  TreeNode(int val){
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};
TreeNode* searchBST(TreeNode* root, int val) {
  if (root == NULL)
    return NULL;
  
  if (root->val == val)
    return root;

  TreeNode *temp = searchBST(root->left,val);
  if (temp)
    return temp;

  temp = searchBST(root->right,val);
  if (temp)
    return temp;

    return NULL;
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
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->left->left->right = new TreeNode(7);
    
    TreeNode *ans = searchBST(root,4);
    std::cout << ans->left->val << std::endl;

    return 0;
}