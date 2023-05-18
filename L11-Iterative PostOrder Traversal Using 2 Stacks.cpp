// Iterative postOrder Traversal of Binary Tree using 2-Stack Data Structure
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

// Iterative PostOrder Traversal
void postOrder(TreeNode* root){
    if(root == NULL) return;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    st1.push(root);
    while(!st1.empty()){
        TreeNode* topNode = st1.top();
        st1.pop();
        st2.push(topNode);
        if(topNode->left) st1.push(topNode->left);
        if(topNode->right) st1.push(topNode->right);
    }
    while(!st2.empty()){
        cout<<st2.top()->data<<endl;
        st2.pop();
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
    
    cout<<"The PostOrder Traversal of the given binary tree is : "<<endl;
    postOrder(root);
    return 0;
}