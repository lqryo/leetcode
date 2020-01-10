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


using namespace std;




// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 


class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL) return;

		deque<ListNode*> m_deque;
		ListNode* cur;

		cur = head;
		while (cur != NULL)
		{
			m_deque.push_back(cur);
			cur = cur->next;
		}

		ListNode* pre = new ListNode(0);
		bool isfront = true;
		while (!m_deque.empty()) {
			if (isfront) {
				cur = m_deque.front();
				m_deque.pop_front();
			}
			else {
				cur = m_deque.back();
				m_deque.pop_back();
			}
			pre->next = cur;
			pre = cur;
			isfront = !isfront;
		}
		cur->next = NULL;  // don't miss it
	
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	s.reorderList(head);

	cin.get();
}
