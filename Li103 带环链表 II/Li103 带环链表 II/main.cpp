#include <iostream>
#include <vector>


using namespace std;


/** Definition of ListNode*/
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
	* @return: The node where the cycle begins.
	*           if there is no cycle, return null
	*/
	ListNode *detectCycle(ListNode *head) {
		// write your code here

		if (head==NULL||head->next==NULL)
		{
			return NULL;
		}

		ListNode *pSlow, *pFast;
		pSlow = head;
		pFast = head;

		while (pFast!=NULL)
		{
			pFast = pFast->next;
			if (pFast !=NULL)
			{
				pFast = pFast->next;
			}		
			pSlow = pSlow->next;
			if (pFast == pSlow) break;
		}

		if (pFast==NULL)
		{
			return NULL;
		}
		else
		{
			pSlow = head;
			while (pSlow!=pFast)
			{
				pSlow = pSlow->next;
				pFast = pFast->next;
			}
			return pSlow;

		}
	}
};



int main()
{

	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	ListNode* ptail=head->next->next->next = new ListNode(4);

	ptail->next = head->next;

	Solution testCase;

	cout << testCase.detectCycle(head)->val << endl;

	getchar();
	return 0;
}