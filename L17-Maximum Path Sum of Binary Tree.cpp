// Program to find the maximum path sum in the Binary Tree
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

int helper(TreeNode* root, int& maxSum){
    if(root == NULL) return 0;
    int left = helper(root->left, maxSum);
    if(left < 0) left = 0;
    int right = helper(root->right, maxSum);
    if(right < 0) right = 0;
    if(maxSum < root->data + left + right) maxSum = root->data + right + left;
    return root->data + max(left, right);
}
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    helper(root, maxSum);
    return maxSum;
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
    
    cout<<"The Maximum path sum of the given binary tree is : ";
    cout<<maxPathSum(root)<<endl;
    return 0;
}