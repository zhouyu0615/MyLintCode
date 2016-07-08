#include <iostream>


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
	* @param head: The first node of linked list.
	* @return: head node
	*/
	ListNode *deleteDuplicates(ListNode *head) {
		// write your code here
		if (head==NULL||head->next==NULL)
		{
			return head;
		}

		ListNode* prv = head;
		ListNode* pNext = prv->next;

		while (pNext != NULL)
		{
			if (pNext->val==prv->val)
			{
				ListNode* temp = pNext;				
				pNext = pNext->next;
				prv->next = pNext;
				free(temp);
			}
			else
			{
				prv = pNext;
				pNext = pNext->next;
			}
		}

		return head;
	}
};