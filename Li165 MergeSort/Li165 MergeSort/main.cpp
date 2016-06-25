#include <iostream>
#include <vector>

using namespace std;


/* Definition of ListNode*/

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
	* @param ListNode l1 is the head of the linked list
	* @param ListNode l2 is the head of the linked list
	* @return: ListNode head of linked list
	*/
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		// write your code here
	
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		ListNode* fake = new ListNode(0);
		ListNode* pTail=fake;

		while (l1!=NULL&&l2!=NULL)
		{
			if (l1->val<l2->val)
			{
				pTail->next = l1;
				l1 = l1->next;
			}
			else
			{
				pTail->next = l2;
				l2 = l2->next;
			}
			pTail = pTail->next;
		}

		if (l1==NULL)
		{
			pTail->next = l2;
		}
		else
		{
			pTail->next = l1;
		}

		return fake->next;

	}
};



int main()
{

	getchar();
	return 0;
}