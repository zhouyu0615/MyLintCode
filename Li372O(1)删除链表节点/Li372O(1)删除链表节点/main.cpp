#include <iostream>
#include <vector>

using namespace std;



/*Definition of ListNode*/

class ListNode {
 public:
     int val;
     ListNode *next;
     ListNode(int val) {
         this->val = val;
         this->next = NULL;
     }
};

class Solution {
public:
	/**
	* @param node: a node in the list should be deleted
	* @return: nothing
	*/
	void deleteNode(ListNode *node) {
		if (node==NULL||node->next==NULL)
		{
			return;
		}
		ListNode* pNext = node->next;

		node->val = pNext->val;
		node->next = pNext->next;
		free(pNext);
	}
};





int main()
{

	getchar();
	return 0;
}