// Level Order Traversal of Binary Tree Using Queue Data Structure
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

// print the level order traversal
void levelOrder(TreeNode* root){
    if(root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* front = q.front();
        cout<<front->data<<endl;
        q.pop();
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    }
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

    cout<<"The Level Order Traversal of the given binary tree is : "<<endl;
    levelOrder(root);
    return 0;
}