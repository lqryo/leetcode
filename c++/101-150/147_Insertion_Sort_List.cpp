#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <stack>


using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 


class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL) return head;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		ListNode* cur = head->next;
		head->next = NULL;

		while (cur != NULL)
		{
			ListNode* p = dummy;
			while (p->next != NULL && p->next->val < cur->val)
			{
				p = p->next;
			}
			// p为待插入位置的前一个节点指针
			ListNode* tmp = cur->next;
			cur->next = p->next;
			p->next = cur;
			cur = tmp;
		}

		return dummy->next;

	}
};



int main()
{
	


	cin.get();
}
