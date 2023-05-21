// Program to check for symmetrical property
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

bool helper(TreeNode* first, TreeNode* second){
    if(first == NULL && second == NULL) return true;
    if(first == NULL || second == NULL) return false;
    return (first->data == second->data && 
        helper(first->left, second->right) && 
        helper(first->right, second->left));
}

bool isSymmetric(TreeNode* root) {
    return helper(root->left, root->right);
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
    
    if(isSymmetric(root))
        cout<<"The Given Binary Tree is Symmetric.";
    else
        cout<<"The Given Bianry Tree is not Symmetric.";
    return 0;
}