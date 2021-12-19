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
  /* data */
  int data;
  Node *left,*right;
  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  };
};

void levelOrder(Node *root){
  if (root == NULL)
    return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
      Node *temp = q.front();
      std::cout << temp->data << std::endl;
      if (temp->left) q.push(temp->left);
      if (temp->right) q.push(temp->right);
      q.pop();
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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(7);
    levelOrder(root);

    return 0;
}