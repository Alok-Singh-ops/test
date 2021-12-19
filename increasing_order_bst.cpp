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
  int val;
  TreeNode *left,*right;
  TreeNode(int data){
    this->val = data;
    this->left = NULL;
    this->right = NULL;
  }
};

void inorder(TreeNode* root, vector<TreeNode*>& data)
    {
        if(root)
        {
            inorder(root->left,data);
            data.push_back(root);
            inorder(root->right,data);
        }
    }

    TreeNode* increasingBST(TreeNode* root) 
    {
        vector<TreeNode*> data;
        inorder(root,data);
        TreeNode* cur = data[0];
        data[0]->left = nullptr;
        data[0]->right = nullptr;
        for(int i = 1; i < data.size(); i++)
        {
            cur->right = data[i];
            data[i]->left = nullptr;
            data[i]->right = nullptr;
            cur = cur->right;
        }
        return data[0];
    }


int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r", stdin);
      freopen("output.txt","w", stdout);
    #endif//


    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);
    // vector<TreeNode*> ans = increasingBST(root);
    TreeNode* ans =  increasingBST(root);
    std::cout << ans->val << std::endl;
  
    

    
    return 0;
}