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
	 bool hasPathSum(TreeNode* root, int sum) {
		 if (root == NULL) return false;

		 sum -= root->val;
		 if (root->left == NULL && root->right == NULL) {
			 return sum == 0;
		 }

		 return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
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

//	cout << s.minDepth(root) << endl;

	std::cin.get();
}
