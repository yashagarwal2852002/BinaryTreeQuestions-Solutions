// Program to find the diameter of the Binary Tree
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

int height(TreeNode* root, int& maxLen){
    if(root == NULL) return 0;
    int left = height(root->left, maxLen);
    int right = height(root->right, maxLen);
    if(maxLen < left + right) maxLen = left + right;
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxLen = 0;
    height(root, maxLen);
    return maxLen;
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
    
    cout<<"The Diameter of the given Binary Tree is : "<<diameterOfBinaryTree(root)<<endl;
    return 0;
}