// Iterative inOrder Traversal of Binary Tree using Stack Data Structure
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

// Iterative Inorder Traversal
void inOrder(TreeNode* root){
    if(root == NULL) return;
    stack<TreeNode*> st;
    TreeNode* currNode = root;
    while(true){
        if(currNode != NULL){
            st.push(currNode);
            currNode = currNode->left;
        }else{
            if(st.empty()) return;
            TreeNode* temp = st.top();
            st.pop();
            cout<<temp->data<<endl;
            currNode = temp->right;
        }
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
    
    cout<<"The InOrder Traversal of the given binary tree is : "<<endl;
    inOrder(root);
    return 0;
}