// Program to print the path from root to a given node 
// in the given Binary Tree
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

int helper(TreeNode* root, int x, vector<int>& ans){
	if(root == NULL) return INT_MIN;
	if(root->data == x){
		ans.push_back(root->data);
		return root->data;
	}
	int left = helper(root->left, x, ans);
	int right = helper(root->right, x, ans);

	if(left == INT_MIN && right == INT_MIN) return INT_MIN;
	ans.push_back(root->data);
	return root->data;
}

void pathInATree(TreeNode* root, int x){
    vector<int> ans;
	helper(root, x, ans);
	reverse(ans.begin(), ans.end());
	for(int i : ans) cout<<i<<endl;
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
    cout<<"The Path from root to given node is : "<<endl;
    pathInATree(root, 11);
    return 0;
}