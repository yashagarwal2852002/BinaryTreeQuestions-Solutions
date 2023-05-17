// Iterative preorder Traversal of Binary Tree using Stack Data Structure
#include<bits/stdc++.h>
using namespace std;

// Binary Tree Node structure
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};

// Iterative preOrder Traversal
void preOrder(TreeNode* root){
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* frontNode = st.top();
        st.pop();
        cout<<frontNode->data<<endl;
        if(frontNode->right) st.push(frontNode->right);
        if(frontNode->left) st.push(frontNode->left);
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
    
    cout<<"The PreOrder Traversal of the given binary tree is : "<<endl;
    preOrder(root);
    return 0;
}