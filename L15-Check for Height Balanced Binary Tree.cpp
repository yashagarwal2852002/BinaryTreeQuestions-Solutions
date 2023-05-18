// Program to check for the Balanced Binary Tree
#include<bits/stdc++.h>
using namespace std;

// Binary Tree Node Structure
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};

int height(TreeNode* root, bool& isbalanced){
    if(root == NULL) return 0;
    int left = height(root->left, isbalanced);
    if(isbalanced == false) return 0;
    int right = height(root->right, isbalanced);
    if(abs(left-right) > 1) isbalanced = false;
    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root){
    bool isbalanced = true;
    height(root, isbalanced);
    return isbalanced;
}

int main(){
    // constructing the tree
    //          1
    //         / \
    //        2   3
    //       / \ / \
    //      4  5 6  7
    TreeNode* root = new TreeNode(1);
    
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    if(isBalanced(root)){
        cout<<"The Given Binary Tree is Height Balanced Binary Tree.";
    }else{
        cout<<"The Given Binary Tree is not the Height Balanced Binary Tree.";
    }
    return 0;
}