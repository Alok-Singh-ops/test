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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (p->val > root->val && q->val > root->val)
    return lowestCommonAncestor(root->right,p,q);
    else if (p->val < root->val && q->val < root->val )
    return lowestCommonAncestor(root->left,p,q);
    else return root;
}

int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    return 0;
}