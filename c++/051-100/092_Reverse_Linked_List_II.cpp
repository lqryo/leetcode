#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || m == n) return head;

		// 使用哑节点
		ListNode dumpList(0);
		dumpList.next = head;
		int index = 1;

		ListNode* Pm_before, *Pm, *Pn,*Pn_after;
		ListNode* pre = &dumpList;
		ListNode* cur = pre->next;

		while (cur!= NULL)
		{
			if (index >= m && index <= n) {
				if (index == m) {
					Pm_before = pre;
					Pm = cur;
					pre = cur;
					cur = cur->next;

				}
				else if (index == n) {
					Pn = cur;
					Pn_after = cur->next;
					ListNode* tmp = cur->next;
					cur->next = pre;
					pre = cur;
					cur = tmp;

				}
				else {
					ListNode* tmp = cur->next;
					cur->next = pre;
					pre = cur;
					cur = tmp;
				}

			}
			else {
				pre = cur;
				cur = cur->next;
			}

			index++; 
		}
		Pm_before->next = Pn;
		Pm->next = Pn_after;

		return dumpList.next;
	}
};





int main()
{
	Solution s;


	std::cin.get();
}
