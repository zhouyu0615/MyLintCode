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
	* @param root the root of binary tree
	* @param target an integer
	* @return all valid paths
	*/
	vector<vector<int>> binaryTreePathSum(TreeNode *root, int target)
	{
		if (root == NULL)
		{
			return result;
		}
		binTreeSearch(root, target);
		return result;
	}

private:
	vector<vector<int>> result;
	vector<int> temp;

	void binTreeSearch(TreeNode* tNode, int target)
	{
		if (tNode==NULL)
		{
			return;
		}
		temp.push_back(tNode->val);
		target = target - tNode->val;
		if (tNode->left== NULL&&tNode->right==NULL&&target == 0)
		{
			result.push_back(temp);
			temp.pop_back();
			return;
		}
		if (tNode->left!=NULL)
		{
			binTreeSearch(tNode->left, target);
		}
		if (tNode->right!=NULL)
		{
			binTreeSearch(tNode->right, target);
		}
		
		temp.pop_back();
	}

};


int main()
{
	Solution testCase;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(4);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(3);

	vector<vector<int>> result = testCase.binaryTreePathSum(root,5);

	for (int i = 0; i < result.size();i++)
	{
		for (int j = 0; j < result[i].size();j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}