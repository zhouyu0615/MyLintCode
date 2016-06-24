#include <iostream>
#include <vector>


using namespace std;

/* Definition of TreeNode*/
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
	* @param T1, T2: The roots of binary tree.
	* @return: True if T2 is a subtree of T1, or false.
	*/
	bool isSubtree(TreeNode *T1, TreeNode *T2) {
		// write your code here
		if (T2==NULL)
		{
			return true;
		}

		if (T1 == NULL)
		{
			return false;
		}

		bool result = false;
		if (T1->val==T2->val)
		{
			result=DosT1HasT2(T1, T2);
		}
		if (!result)
		{
			result=isSubtree(T1->left, T2);
		}
		if (!result)
		{
			result=isSubtree(T1->right, T2);
		}
		return result;
	}

private:
	bool DosT1HasT2(TreeNode* root1, TreeNode* root2)
	{
		if (root1==NULL&&root2==NULL)
		{
			return true;
		}
		if (root1==NULL||root2==NULL)
		{
			return false;
		}
		if (root1->val!=root2->val)
		{
			return false;
		}
		return DosT1HasT2(root1->left, root2->left) && DosT1HasT2(root1->right, root2->right);
	}
};


int main()
{

	getchar();
	return 0;
}
