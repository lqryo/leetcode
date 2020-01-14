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
	ListNode* reverseList(ListNode* head) {
		ListNode* dummyNode = new ListNode(0);

		dummyNode->next = head;
		ListNode* cur = dummyNode->next;
		ListNode* pre = NULL;
		while (cur!= NULL)
		{
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}

		return pre;

	}
};


 


int main()
{
	Solution s;
	ListNode* node = new ListNode(1);
	node->next = new ListNode(2);
	node->next->next = new ListNode(3);
	node->next->next->next = new ListNode(4);
	node->next->next->next->next = new ListNode(5);
	s.reverseList(node);

	cin.get();
}
