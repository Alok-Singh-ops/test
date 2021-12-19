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



vector<double> averageOfLevels(TreeNode* root) {
  vector<double> ans;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
      TreeNode *temp = q.front();
      q.pop();
      sum += temp->val;
      if (temp->left != NULL)
        q.push(temp->left);
      if (temp->right != NULL)
        q.push(temp->right);
    }
    ans.push_back(sum/size);
  }
  
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
  
  TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);


    return 0;
}


