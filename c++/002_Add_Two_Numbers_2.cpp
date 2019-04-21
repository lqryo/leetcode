/*
******正确版本*****
*/
#include <vector>
#include <map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* ans = NULL;
	ListNode* head = NULL;


	int carry = 0;
	int sum;
	while (l1 != NULL || l2 != NULL || carry) //注意要考虑进位
	{
		if (l1 != NULL && l2 != NULL)
		{
			sum = (l1->val + l2->val + carry) % 10;
			carry = (l1->val + l2->val + carry) / 10;
			l1 = l1->next;
			l2 = l2->next;
		}
		else if (l1 != NULL)
		{
			sum = (l1->val + carry) % 10;
			carry = (l1->val + carry) / 10;
			l1 = l1->next;
		}
		else if (l2 != NULL)
		{
			sum = (l2->val + carry) % 10;
			carry = (l2->val + carry) / 10;
			l2 = l2->next;
		}
		else if (carry == 1)
		{
			sum = 1;
			carry = 0;
		}

		if (!ans) //the first element
		{
			ListNode* newnode = new ListNode(sum);
			ans = newnode;
			head = ans;
		}
		else
		{
			ListNode* newnode = new ListNode(sum);
			head->next = newnode;
			head = head->next;
		}

	}
	return ans;
}


int main()
{
	ListNode l1(2);
	l1.next = new ListNode(4);
	l1.next->next = new ListNode(3);

	ListNode l2(5);
	l2.next = new ListNode(6);
	l2.next->next = new ListNode(4);

	ListNode* l3 = NULL;
	
	Solution solution;
	l3 = solution.addTwoNumbers(&l1, &l2);

	return 0;
}





