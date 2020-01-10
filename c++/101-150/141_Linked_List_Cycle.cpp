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
 
// 快慢指针

class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != NULL)
		{
			if (fast->next != NULL && fast->next->next != NULL) {
				fast = fast->next->next;
				slow = slow->next;
			}
			else {
				return 0;
			}
			if (fast == slow) return 1;
		}
		return 0;
	}
};
