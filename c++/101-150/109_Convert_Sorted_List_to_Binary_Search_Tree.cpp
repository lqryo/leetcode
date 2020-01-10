#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <glog/logging.h>

using namespace std;

// Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



// Definition for a binary tree node.
 struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 // 按照二分的思想，中点作为根节点
 // 中点左边的树作为左子树，右边作为右子树
 
 class Solution {
 public:
	 TreeNode* sortedListToBST(ListNode* head) {
		 //先遍历链表
		 while (head != NULL) {
			 nums.push_back(head->val);
			 head = head->next;
		 }

		 return fun(0, nums.size() - 1);
	 }
 private:
	 vector<int> nums;
	 TreeNode* fun(int start, int end)
	 {
		 if (start > end) return NULL;
		 
		 int mid = (start + end) / 2;
		 TreeNode* root = new TreeNode(nums[mid]);
		 root->left = fun(start, mid - 1);
		 root->right = fun(mid + 1, end);

		 return root;
	 }
 };



int main(int argc, char* argv[])
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution s;
//	cout << s.maxDepth(root) << endl;
	

	std::cin.get();
}
