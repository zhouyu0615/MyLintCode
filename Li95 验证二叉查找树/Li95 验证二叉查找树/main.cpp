#include <iostream>
#include <vector>


using namespace std;



/* Definition of TreeNode:*/

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
	* @return: True if the binary tree is BST, or false
	*/
	bool isValidBST(TreeNode *root) {
		// write your code here
		if (root==NULL||(root->left==NULL&&root->right==NULL))
		{
			return true;
		}
		
		return isValid(root, LONG_MIN, LONG_MAX);	
	}

private:

	bool isValid(TreeNode* root, long long  MinVal, long long maxVal)
	{
		if (root==NULL)
		{
			return true;
		}
		
		if (root->val<=MinVal||root->val>=maxVal)
		{
			return false;
		}

		return isValid(root->left, MinVal, root->val) && isValid(root->right, root->val, maxVal);

	}
};



int  main()
{

	getchar();
	return 0;
}