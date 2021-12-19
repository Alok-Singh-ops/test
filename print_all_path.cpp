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

 vector<vector<int>> ans;
 vector<int> v;


void traverse(tree *root){
  if (root == NULL)
    return;
    v.push_back(root->data);
    traverse(root->left);
    if (root->left == NULL && root->right == NULL)
    {
      ans.push_back(v);
    }
    traverse(root->right);
    v.pop_back();
}

vector<vector<int>> Paths(tree* root)
{
  traverse(root);
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

    tree* root = new tree(10);
    root->left = new tree(20);
    root->right = new tree(30);
    root->left->left = new tree(40);
    root->left->right = new tree(60);
    // root->left->left->left = new tree(1);
    // root->right->right = new tree(8);
    // root->right->right->left = new tree(7);
    // root->right->right->right = new tree(9);
    vector<vector<int>> op = Paths(root);

    for (int i = 0; i < op.size(); i++)
    {
      for (int j = 0; j < op[0].size(); j++)
      {
        std::cout << op[i][j] << " ";
      }
      std::cout <<std::endl;
    }
    
    

    
    return 0;
}