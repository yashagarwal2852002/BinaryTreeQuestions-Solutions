// Program to print the Bottom View
// of the given Binary Tree
#include<bits/stdc++.h>
using namespace std;

// Binary Tree Structure Node
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};

void bottomView(TreeNode *root){
    if(root == NULL) return;
    map<int, int> mp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto frontNode = q.front();
        q.pop();
        mp[frontNode.second] = frontNode.first->data;
        if(frontNode.first->left) q.push({frontNode.first->left, frontNode.second - 1});
        if(frontNode.first->right) q.push({frontNode.first->right, frontNode.second + 1});
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout<<it->second<<endl;
    }
}

// Main Function
int main(){
    // constructing the tree1
    //           1
    //        /     \
    //       2        3
    //     /  \      /  \
    //    4    5    6    7
    //   /\   /\   / \   / \
    //  8 9 10 11 12 13 14 15
    TreeNode* root = new TreeNode(1);
    
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);
    
    cout<<"Bottom View of the Given Binary Tree is : "<<endl;
    bottomView(root);
    return 0;
}