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



 class Solution {
 public:
	 int minDepth(TreeNode* root) {
		 // 特殊情况
		 if (root == NULL) return 0;

		 vector<TreeNode*> level;
		 int ans = 1;
		 level.push_back(root);
		 while (level.size() != 0)
		 {
			 vector<TreeNode*> level_copy;
			 level.swap(level_copy);

			 for (auto x : level_copy)
			 {
				 if (x == NULL) continue;
				 if (x->left == NULL && x->right == NULL) return ans;
				 level.push_back(x->left);
				 level.push_back(x->right);
			 }
			 ans++;
		 }
		 return ans;
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

	cout << s.minDepth(root) << endl;

	std::cin.get();
}
