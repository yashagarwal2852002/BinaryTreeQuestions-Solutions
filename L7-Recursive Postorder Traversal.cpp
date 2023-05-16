// Recursive Postorder traversal - Left Right Root
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

void postorderTraversal(TreeNode* root){
    if(root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<endl;
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
    
    cout<<"The Postorder Traversal of Binary Tree : "<<endl;
    postorderTraversal(root);
    return 0;
}