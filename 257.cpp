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

string path;

void pre(TreeNode* root,string str,vector<string> &ans)
{
  if(root == NULL)
  return;
  str+= to_string(root->val);
  if(root->left == NULL && root->right == NULL)
  {
    ans.push_back(str);
    return;
  }
  str+="->";
  pre(root->left,str,ans);
  pre(root->right,str,ans);
}

vector<string> binaryTreePaths(TreeNode* root) {
  vector<string> ans;
  pre(root,"",ans);
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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(9);

  vector<string> ans = binaryTreePaths(root);
  for(auto it: ans)
    std::cout << it << std::endl;

    return 0;
}