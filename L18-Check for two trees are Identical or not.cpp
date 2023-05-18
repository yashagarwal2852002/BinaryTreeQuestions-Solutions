// Program to check if two trees are identical or not
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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    return (p->data == q->data && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main(){
    // constructing the tree1
    //          1
    //         / \
    //        2   3
    //       / \ / \
    //      4  5 6  7
    TreeNode* root1 = new TreeNode(1);
    
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);
    
    
    // constructing the tree2
    //          1
    //         / \
    //        2   3
    //       / \ / \
    //      4  5 6  7
    TreeNode* root2 = new TreeNode(1);
    
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);
    
    if(isSameTree(root1, root2)){
        cout<<"Both the Trees are Identical"<<endl;
    }else{
        cout<<"Trees are not identical/same."<<endl;
    }
    return 0;
}