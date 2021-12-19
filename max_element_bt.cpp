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

struct Node
{
  int data;
  Node *left,*right;
  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  };
};

int findMax(Node *root)
{
  if (root == NULL)
    return 0;

  int res = root->data;
  int lres = findMax(root->left);
  int rres = findMax(root->right);
  if (lres>res)
    res = lres;
  if (rres>res)
    res = rres;


  return res;
}

int findMin(Node *root)
{
  if (root == NULL)
  return INT_MAX;

  int res = root->data;
  int lres = findMin(root->left);
  int rres = findMin(root->right);
  if (lres<res)
    res = lres;
  if (rres<res)
    res = rres;


  return res;

  
}

int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//
    Node *root = new Node(2);
    root->left = new Node(7);
    root->right = new Node(5);
    root->left->right = new Node(6);
    root->right->right = new Node(9);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(1);
    root->right->right->left = new Node(4);


    std::cout << findMax(root) << std::endl;
    std::cout << findMin(root) << std::endl;

    return 0;
}