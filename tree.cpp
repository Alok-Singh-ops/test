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

struct tree
{
  /* data */
  int data;
  struct tree *left, *right;
  tree(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  };
};

//preorder
void preOrder(struct tree *node){
  if (node == NULL)
    return;
  std::cout << node->data << " " <<std::endl;
  preOrder(node->left);
  preOrder(node->right);
}

void inOrder(struct tree *node){
  if (node ==NULL)
  return;
  inOrder(node->left);
  std::cout << node->data << " " <<std::endl;
  inOrder(node->right);
}

void postOrder(struct tree *node){
  if (node == NULL)
  return;
  postOrder(node->left);
  postOrder(node->right);
  std::cout << node->data << std::endl;
}

int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//
    tree* root = new tree(5);
    root->left = new tree(3);
    root->right = new tree(6);
    root->left->left = new tree(2);
    root->left->right = new tree(4);
    root->left->left->left = new tree(1);
    root->right->right = new tree(8);
    root->right->right->left = new tree(7);
    root->right->right->right = new tree(9);
    




    inOrder(root);
    // std::cout <<std::endl;
    // inOrder(root);
    // std::cout <<std::endl;
    // postOrder(root);
    return 0;
}