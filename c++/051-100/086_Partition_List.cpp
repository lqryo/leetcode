#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 参考：https://leetcode-cn.com/problems/partition-list/solution/fen-ge-lian-biao-by-leetcode/
// 注意哑节点的使用技巧

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 class Solution {
 public:
	 ListNode* partition(ListNode* head, int x) {
		 ListNode before(0);
		 ListNode after(0);

		 ListNode* p1 = &before;
		 ListNode* p2 = &after;

		 ListNode* cur = head;
		 while (cur != NULL) {
			 if (cur->val < x) {
				 p1->next = cur;
				 p1 = p1->next;
			 }
			 else {
				 p2->next = cur;
				 p2 = p2->next;
			 }
			 cur = cur->next;
		 }

		 p1->next = NULL;
		 p2->next = NULL;
		 if (before.next == NULL) {
			 return after.next;
		 }
		 else {
			 p1->next = after.next;
			 return before.next;
		 }

	 }
 };




int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(2);

	Solution s;
	ListNode* ans = s.partition(head,3);

	std::cin.get();
}
