// Program to print the Vertical Order Traversal
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

void helper(TreeNode* root, int col, int row, map<pair<int, int>, multiset<int>>& mp){
    if(root == NULL) return;
    mp[{col, row}].insert(root->data);
    helper(root->left, col-1, row+1, mp);
    helper(root->right, col+1, row+1, mp);
}
void verticalTraversal(TreeNode* root) {
    map<pair<int, int>, multiset<int>> mp;
    helper(root, 0,  0, mp);
    for(auto it = mp.begin(); it != mp.end(); it++){
        for(auto it1 = it->second.begin(); it1 != it->second.end(); it1++)
            cout<<*it1<<endl;
    }
}

// Main Function
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
    
    cout<<"The Vertical Order Traversal of the Given Binary Tree is : "<<endl;
    verticalTraversal(root);
    return 0;
}