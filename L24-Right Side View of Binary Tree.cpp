// Program to print the Right Side View
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

void rightSideView(TreeNode* root) {
    if(root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i<n; i++){
            if(i == n-1) cout<<q.front()->data<<endl;
            TreeNode* frontNode = q.front();
            q.pop();
            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);
        }
    }
}

// Main Function
int main(){
    // constructing the tree1
    //           1
    //        /     \
    //       2        3
    //     /  \      /  \
    //    4    5    6    7
    //   /\   /\   / \   / \
    //  8 9 10 11 12 13 14 15
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
    
    cout<<"Right Side View of the Given Binary Tree is : "<<endl;
    rightSideView(root);
    return 0;
}