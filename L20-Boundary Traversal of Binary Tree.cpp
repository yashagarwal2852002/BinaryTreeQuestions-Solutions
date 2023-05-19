// Program to print the Bounary Traversal
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

// Prints the left boundary without the root node and leaf node
void leftBoundary(TreeNode* root){
    if(root->left == NULL && root->right == NULL) return;
    cout<<root->data<<endl;
    if(root->left != NULL) leftBoundary(root->left);
    else leftBoundary(root->right);
}

// Print the leaf nodes
void leafNodes(TreeNode* root){
    if(root->left == NULL && root->right == NULL) cout<<root->data<<endl;
    if(root->left) leafNodes(root->left);
    if(root->right) leafNodes(root->right);
}

// Print the right boundary without root and leaf node
void rightBoundary(TreeNode* root){
    if(root->left == NULL && root->right == NULL) return;
    if(root->right != NULL) rightBoundary(root->right);
    else rightBoundary(root->left);
    cout<<root->data<<endl;
}

// Print the whole boundary traversal
void boundary(TreeNode *root){
    cout<<root->data<<endl;
    if(root->left == NULL && root->right == NULL) return;
    if(root->left) leftBoundary(root->left);
    leafNodes(root);
    if(root->right) rightBoundary(root->right);
}

// Main Function
int main(){
    // constructing the tree1
    //           1
    //        /     \
    //       2        3
    //     /  \      /  \
    //    4    5     6    7
    //   /\   /\    / \   / \
    //  8 9 10 11  12 13 14 15
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
    
    cout<<"The Boundary Traversal of the Given Binary Tree is : "<<endl;
    boundary(root);
    return 0;
}