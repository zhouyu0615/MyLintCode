#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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



class Solution2 {
	/**
	* @param root: The root of binary tree.
	* @return: A list of lists of integer include
	*          the zigzag level order traversal of its nodes' values
	*/
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode *root)
	{
		// write your code here
		vector<vector<int>> result;
		if (root == NULL)	{
			return result;
		}
		TreeNode* levelFlag = new TreeNode(0);
		queue<TreeNode*> tNodeQueue;
		tNodeQueue.push(root);
		tNodeQueue.push(levelFlag);
		vector<int> temp;
		while (!tNodeQueue.empty())
		{
			TreeNode* tNode = tNodeQueue.front();
			tNodeQueue.pop();
			if (tNode == levelFlag)
			{
				result.push_back(temp);
				temp.clear();
				if (!tNodeQueue.empty())
				{
					tNodeQueue.push(levelFlag);
				}
				continue;
			}
			temp.push_back(tNode->val);
			if (tNode->left != NULL){
				tNodeQueue.push(tNode->left);
			}
			if (tNode->right != NULL){
				tNodeQueue.push(tNode->right);
			}
		}
		free(levelFlag);
		for (int i = 0; i < result.size(); i++)
		{
			if (i % 2 == 1)
			{
				reverse(result[i].begin(), result[i].end());
			}
		}
	return result;
	}
};



class Solution {
	/**
	* @param root: The root of binary tree.
	* @return: A list of lists of integer include
	*          the zigzag level order traversal of its nodes' values
	*/
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		// write your code here
		vector<vector<int>> result;
		if (root==NULL)
		{
			return result;
		}
		stack<TreeNode*> EvenStack;
		stack<TreeNode*> OddStack;

	
		vector<int> temp;

		int countLevel = 1;
		OddStack.push(root);

		TreeNode* tNode;
		while ((!EvenStack.empty()||!OddStack.empty()))
		{
			if (countLevel%2==1)
			{
				while (!OddStack.empty())
				{
					tNode = OddStack.top();
					OddStack.pop();
					temp.push_back(tNode->val);
					if (tNode->left!=NULL){
						EvenStack.push(tNode->left);
					}
					if (tNode->right!=NULL)
					{
						EvenStack.push(tNode->right);
					}
				}
				result.push_back(temp);
				temp.clear();
			}
			else
			{
				while (!EvenStack.empty())
				{
					tNode = EvenStack.top();
					EvenStack.pop();
					temp.push_back(tNode->val);

					if (tNode->right!=NULL)
					{
						OddStack.push(tNode->right);
					}
					if (tNode->left!=NULL)
					{
						OddStack.push(tNode->left);
					}
				}
				result.push_back(temp);
				temp.clear();
			}	
		 countLevel++;
		}
	return result;
	}
};


int  main()
{

	getchar();
	return 0;
}