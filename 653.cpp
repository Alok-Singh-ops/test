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
  /* data */
  int val;
  struct TreeNode *left, *right;
  TreeNode(int data){
    this->val = data;
    this->left = NULL;
    this->right = NULL;
  };
};

void preOrder(TreeNode *root,vector<int> &temp){
  if (!root)
    return;
    temp.push_back(root->val);
    preOrder(root->left,temp);
    preOrder(root->right,temp);
}

bool findTarget(TreeNode* root, int k) {
  vector<int> temp;
  preOrder(root,temp);
  unordered_map<int,int> mp;
  for (int i = 0; i < temp.size(); i++)
  {
    if (mp.find(k-temp[i]) != mp.end())
      return true;
    else
      mp[temp[i]] = i;
  }

  for(auto it: mp)
    std::cout << it.first <<it.second <<std::endl;

  return false;
}


int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    std::cout << findTarget(root,9) << std::endl;
    return 0;
}