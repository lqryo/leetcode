class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		//先让链表首尾相连
		ListNode* cur = head;
		if (head == nullptr) {
			return nullptr;
		}

		int num = 1;
		while (true) {
			if (cur->next == nullptr)
			{
				cur->next = head;
				break;
			}
			else {
				cur = cur->next;
				num++;
			}
		}

		int step = num - (k % num) - 1;


		cur = head;
		for (int i = 0; i < step; i++)
		{
			cur = cur->next;
		}

		//将cur做为尾节点，cur的next节点做为head
		ListNode* ans = cur->next;
		cur->next = nullptr;


		return ans;
	}
};