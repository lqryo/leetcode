#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <glog/logging.h>

using namespace std;




// Definition for a binary tree node.
 struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 参考：https://leetcode-cn.com/problems/balanced-binary-tree/solution/balanced-binary-tree-di-gui-fang-fa-by-jin40789108/
// 递归+提前阻断

 class Solution {
 public:
	 bool isBalanced(TreeNode* root) {
		 return depth(root) != -1;
	 }
 private:
	 
	 int depth(TreeNode* root)
	 {
		 if (root == NULL) return 0;
		 int left = depth(root->left);
		 if (left == -1) return - 1;
		 
		 int right = depth(root->right);
		 if (right == -1) return -1;

		 int diff = abs(left - right);
		 if (diff > 1) return -1;
		 else return max(left, right) + 1;
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

	

	std::cin.get();
}
