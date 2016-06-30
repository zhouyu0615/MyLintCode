#include <iostream>
#include <vector>

using namespace std;



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
/* Definition of Doubly-ListNode*/

class DoublyListNode {
public:
     int val;
     DoublyListNode *next, *prev;
     DoublyListNode(int val) {
         this->val = val;
		 this->prev = this->next = NULL;
     }
};

class Solution {
public:
	/**
	* @param root: The root of tree
	* @return: the head of doubly list node
	*/
	DoublyListNode* bstToDoublyList(TreeNode* root) {
		// Write your code here
		InorderTravel(root);

		if (result.size()==0)
		{
			return NULL;
		}
		
		DoublyListNode* head = new DoublyListNode(result[0]);
		DoublyListNode* pTail = head;
		for (int i = 1; i < result.size();i++)
		{
			DoublyListNode* temp = new DoublyListNode(result[i]);
			pTail->next = temp;
			temp->prev = pTail;
			pTail = temp;
		}

		return head;
	}
private:
	vector<int> result;
	void InorderTravel(TreeNode* tNode)
	{
		if (tNode==NULL)
		{
			return;
		}
		InorderTravel(tNode->left);
		result.push_back(tNode->val);
		InorderTravel(tNode->right);
	}
};




int main()
{

	getchar();
	return 0;
}