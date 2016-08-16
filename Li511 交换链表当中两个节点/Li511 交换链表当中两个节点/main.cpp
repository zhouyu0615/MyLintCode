#include <iostream>
#include <vector>


using namespace std;
/* Definition for singly-linked list.*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/**
	* @param head a ListNode
	* @oaram v1 an integer
	* @param v2 an integer
	* @return a new head of singly-linked list
	*/
	ListNode* swapNodes(ListNode* head, int v1, int v2) {
		// Write your code here

		if (head==NULL||head->next==NULL)
		{
			return head;
		}
		ListNode* fake = new ListNode(0);
		fake->next = head;

		ListNode * p,*p1, *p2;
		p = fake;
		p1 = NULL;
		p2 = NULL;

		while (p->next!=NULL)
		{
			if (p->next->val==v1)
			{
				p1 = p;
			}else if (p->next->val == v2)
			{
				p2 = p;
			}

			p = p->next;
			if (p1 != NULL&&p2 != NULL)
			{
				break;
			}
		}

		if (p1!=NULL&&p2!=NULL)
		{
			ListNode *temp,*prv1,*prv2;
			prv1 = p1;
			p1 = p1->next;
			prv2 = p2;
			p2 = p2->next;

			if ((p1!=prv2)&&(p2!=prv1))
			{
				temp = p2->next;
				p2->next = p1->next;
				p1->next = temp;

				temp = prv2->next;
				prv2->next = prv1->next;
				prv1->next = temp;
			}
			else if (p1==prv2)
			{
				prv1->next = p2;
				p1->next = p2->next;
				p2->next = p1;
			}else if (p2==prv1)
			{
				prv2->next = p1;
				p2->next = p1->next;
				p1->next = p2;
			}		
		}
		return fake->next;
	}
};


int main()
{
	ListNode* head = new ListNode(8);
	head->next = new ListNode(10);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	Solution testCase;

	testCase.swapNodes(head, 8, 10);

	getchar();
	return 0;
}