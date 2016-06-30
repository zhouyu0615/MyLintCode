#include <iostream>
#include <vector>
#include <queue>

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
	/**
	* @param root: The root of binary tree.
	* @return: Level order a list of lists of integer
	*/
public:
	vector<vector<int>> levelOrder(TreeNode *root) {
		// write your code here
		vector<vector<int>> result;

		if (root == NULL)
		{
			return result;
		}
		queue<TreeNode*> treeQueue;

		treeQueue.push(root);
		TreeNode* tNode;
		TreeNode* levelFlag = new TreeNode(0);
		treeQueue.push(levelFlag);

		vector<int> temp;
		while (!treeQueue.empty())
		{
			tNode = treeQueue.front();
			treeQueue.pop();


			if (tNode->left!=NULL)
			{
				treeQueue.push(tNode->left);
			}
			if (tNode->right!=NULL)
			{
				treeQueue.push(tNode->right);
			}

			if (tNode==levelFlag)
			{
				result.push_back(temp);
				temp.clear();
				if (!treeQueue.empty())
				{
					treeQueue.push(levelFlag);
				}			
			}
			else
			{
				temp.push_back(tNode->val);
			}
		}
		return result;
	}
};


int main()
{


	getchar();
	return 0;
}