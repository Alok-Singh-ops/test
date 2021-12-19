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

void preOrder(TreeNode *root,string &op){
  if (!root)
    return;
  op.push_back('(');
    op.push_back(root->val+48);
    if (root->right == NULL){
      preOrder(root->left,op);
      op.push_back(')');
    }
    if (root->left == NULL){
      preOrder(root->right,op);
      op.push_back(')');
    }
      
  
  
}

string tree2str(TreeNode* root) {
  string op = "";
  op.push_back(root->val+48);
  preOrder(root->left,op);
  preOrder(root->right,op);

  return op;
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
    root->left->right = new TreeNode(4);
    // root->left->right = new TreeNode(3);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(9);

    std::cout << tree2str(root) << std::endl;
    
    return 0;
}