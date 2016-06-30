#include <iostream>
#include <vector>
#include <map>


using namespace std;


/* Definition for singly-linked list with a random pointer.*/

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
	/**
	* @param head: The head of linked list with a random pointer.
	* @return: A new head of a deep copy of the list.
	*/
	RandomListNode *copyRandomList(RandomListNode *head) {
		// write your code here
		if (head==NULL)
		{
			return head;
		}
		map<RandomListNode*, RandomListNode*>  ramPairs; //key为原链表中的节点，val为新链表中对应的节点//

		RandomListNode *pOld, *pNew;
		RandomListNode* newHead = new RandomListNode(head->label);
		pOld = head->next;
		pNew = newHead;
		ramPairs[head] = newHead;
		while (pOld!=NULL)
		{
			pNew->next = new RandomListNode(pOld->label);
			ramPairs[pOld] = pNew->next;
			pNew = pNew->next;
			pOld = pOld->next;
		}

		pOld = head;
		pNew = newHead;	
		while (pNew!=NULL&&pOld!=NULL)
		{
			pNew->random = ramPairs[pOld->random];
			pNew = pNew->next;
			pOld = pOld->next;
		}
		return newHead;
	}
};





int main()
{

	getchar();
	return 0;
}