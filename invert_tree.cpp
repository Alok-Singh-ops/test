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



TreeNode* invertTree(TreeNode* root) {
  if (root)
  {
    TreeNode *temp;
    temp = root->right;
    root->right = root->left;
    root->left = temp;
    if (root->left != NULL && root->right != NULL)
    {
      invertTree(root->left);
      invertTree(root->right);
    }
    
  }
  return root;
}


void preOrder(struct TreeNode *node){
  if (node == NULL)
    return;
  std::cout << node->val << " " <<std::endl;
  preOrder(node->left);
  preOrder(node->right);
}

void printLevelOrder(TreeNode* root)
{
    // Base Case
    if (root == NULL)
        return;
    // Create an empty queue for level order traversal
    queue<TreeNode*> q;
    // Enqueue Root and initialize height
    q.push(root);
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        TreeNode* node = q.front();
        cout << node->val << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
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
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    TreeNode* root1 = invertTree(root);
    printLevelOrder(root1);
    return 0;
}