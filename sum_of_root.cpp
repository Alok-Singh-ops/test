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
  TreeNode* left,*right;
  TreeNode(int data){
    this->val= data;
    this->left = NULL;
    this->right = NULL;
  };
};

int ans = 5;


void binaryToDecimal(vector<int> &op)
{
  int decimal = 0;

  for (int i = 0; i < op.size(); i++)
  {
    /* code */
    decimal = (decimal*2) * op[i];
  }
  ans += decimal;
}

void traverse(TreeNode *root,vector<int> &op){
  if (root == NULL)
    return;
  op.push_back(root->val);

  traverse(root->left,op);
  if (root->left == NULL && root->right == NULL)
    {
      // std::cout << ans << std::endl;
      binaryToDecimal(op);
    }
    else
    {
      traverse(root->right,op);   
    }
    op.pop_back();
}


int sumRootToLeaf(TreeNode* root) {
  vector<int> op;
  traverse(root,op);
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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    // std::cout << sumRootToLeaf(root) << std::endl;
    std::cout <<  sumRootToLeaf(root)<< std::endl;

    // sumRootToLeaf(root);
    return 0;
}