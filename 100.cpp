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




bool isSameTree(TreeNode* p, TreeNode* q) {
  if (p == NULL && q == NULL)
    return true;
  if (p == NULL || q== NULL)
    return false;
  if (p->val != q->val)
    return false;

  return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
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
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(9);
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    std::cout << isSameTree(root,root1) << std::endl;    
    return 0;
}