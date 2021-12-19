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
  TreeNode(int data){
    this->val = data;
    this->left= NULL;
    this->right = NULL;
  }
};


void helper(TreeNode *root,vector<int> &op,int low,int high){
  if (root == NULL)
    return;
    if (root->val >= low && root->val <= high)
  op.push_back(root->val);
  helper(root->left,op,low,high);
  helper(root->right,op,low,high);
}



int rangeSumBST(TreeNode* root, int low, int high) {
  vector<int> op;
  int ans = 0;
  helper(root,op,low,high);
  for(int it:op)
    ans +=it;
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

    TreeNode *root = new TreeNode(10);
    root->left  = new TreeNode(5);
    root->right =  new TreeNode(15);
    root->left->left = new TreeNode(3);    
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    std::cout << rangeSumBST(root,7,15) << std::endl;


    return 0;
}