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

void fillLeaf(TreeNode *root,vector<int> &temp){
  if (!root)
    return;
  if (root->left == NULL && root->right == NULL)
    temp.push_back(root->val);
    fillLeaf(root->left,temp);
    fillLeaf(root->right,temp);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
  vector<int> r1,r2;
  fillLeaf(root1,r1);
  fillLeaf(root2,r2);
  if (r1 == r2)
    return true;
  return false;
  }

int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    // root1->left->left = new TreeNode(6);
    // root1->left->right = new TreeNode(2);
    // root1->left->right->left = new TreeNode(7);
    // root1->left->right->right = new TreeNode(4);
    // root1->right->left = new TreeNode(9);
    // root1->right->right = new TreeNode(8);

  TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);
    // root2->left->left = new TreeNode(6);
    // root2->left->right = new TreeNode(7);
    // root2->right->left = new TreeNode(4);
    // root2->right->right = new TreeNode(2);
    // root2->right->right->left = new TreeNode(9);
    // root2->right->right->right = new TreeNode(8);


std::cout << leafSimilar(root1,root2) << std::endl;
// leafSimilar(root1,root2);



    return 0;
}