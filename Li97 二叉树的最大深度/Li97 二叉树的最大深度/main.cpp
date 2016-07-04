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
	* @param root: The root of binary tree.
	* @return: An integer
	*/
	int maxDepth(TreeNode *root) {
		// write your code here
		return GetNodeDepth(root);
	}
private:
	int GetNodeDepth(TreeNode* tNode)
	{
		if (tNode==NULL)
		{
			return 0;
		}

		int left = GetNodeDepth(tNode->left);
		int right = GetNodeDepth(tNode->right);
		return (left > right ? left : right) + 1;
	}
};