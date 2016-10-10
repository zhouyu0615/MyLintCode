#include <iostream>


/**
* Definition of TreeNode:*/
 class TreeNode {
 public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
         this->left = this->right = NULL;
     }
 };


class Solution {
public:
	/**
	* @param root: The root of binary tree
	* @return root of new tree
	*/
	TreeNode* cloneTree(TreeNode *root) {
		// Write your code here

		if (root==NULL)
		{
			return root;
		}

		TreeNode* newRoot = new TreeNode(root->val);
		newRoot->left = cloneTree(root->left);
		newRoot->right = cloneTree(root->right);
		return newRoot;
	}
};



int main()
{
	getchar();
	return 0;
}