#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <glog/logging.h>

using namespace std;


 //Definition for a binary tree node.
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
	 TreeNode* sortedArrayToBST(vector<int>& nums) {
		 this->nums = nums;
		 return fun(0, nums.size() - 1);
	 }

 private:
	 vector<int> nums;
	 TreeNode* fun(int start, int end)
	 {
		 if (start > end) return NULL;

		 int mid = (start + end) / 2;
		 TreeNode* node = new TreeNode(nums[mid]);
		 node->left = fun(start, mid - 1);
		 node->right = fun(mid + 1, end);
		 return node;
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
