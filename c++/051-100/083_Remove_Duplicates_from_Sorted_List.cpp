#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode temp(0);
		temp.next = head;

		ListNode* cur = &temp;
		ListNode* next1;
		ListNode* next2 = cur->next;
		while (cur->next != NULL)
		{
			next1 = next2;
			next2 = next1->next;
			if (next2 != NULL && next1->val == next2->val) {
				while (next2->next != NULL && next2->val == next2->next->val)
				{
					next2 = next2->next;
				}
//				next2 = next2->next;
				cur->next = next2;
			}
			else {
				cur = next1;
			}


		}
		return temp.next;

	}
};




int main()
{


	std::cin.get();
}
