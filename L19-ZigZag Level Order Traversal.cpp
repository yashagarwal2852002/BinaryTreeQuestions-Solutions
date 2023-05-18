// Program to print the zig zag level order traversal of
// The Given Binary Tree
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

void zigzagLevelOrder(TreeNode* root) {
    if(root == NULL) return;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    bool lefttoright = true;
    st1.push(root);
    while(!st1.empty() || !st2.empty()){
        if(lefttoright){
            while(!st1.empty()){
                cout<<st1.top()->data<<endl;
                if(st1.top()->left) st2.push(st1.top()->left);
                if(st1.top()->right) st2.push(st1.top()->right);
                st1.pop();
            }
        }else{
            while(!st2.empty()){
                cout<<st2.top()->data<<endl;
                if(st2.top()->right) st1.push(st2.top()->right);
                if(st2.top()->left) st1.push(st2.top()->left);
                st2.pop();
            }
        }
        lefttoright = !lefttoright;
    }
}

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
    
    cout<<"The Zig Zag Level Order Traversal of the Given Binary Tree is : "<<endl;
    zigzagLevelOrder(root);
    return 0;
}