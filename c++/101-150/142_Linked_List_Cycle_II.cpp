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
 

/*
双指针
两次循环，第一次循环是快慢指针，若链表不是环形，则快指针先到表尾NULL。
若是环形，快慢指针会相遇。相遇后将快慢指针之一置到表头head，然后开始第二次循环，此时快慢指针同速移动。
当快慢指针再次相遇时到达链表开始入环的第一个节点。
*/

 class Solution {
 public:
	 ListNode *detectCycle(ListNode *head) {
		 if (head == NULL) return NULL;
		 ListNode* slow = head;
		 ListNode* fast = head;

		 while (true)
		 {
			 if (fast->next == NULL || fast->next->next == NULL) {
				 return NULL;
			 }
			 else {
				 fast = fast->next->next;
				 slow = slow->next;
				 
				 if (fast == slow) break;
			 }
		 }

		 slow = head;

		 while (slow != fast) {
			 slow = slow->next;
			 fast = fast->next;
		 }

		 return slow;
	 }
 };

int main()
{
	

	cin.get();
}
