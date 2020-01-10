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
 
 class Solution {
 public:
	 int maxDepth(TreeNode* root) {
		 if (root == NULL) return 0;
		 vector<TreeNode*> cur;
		 cur.push_back(root);
		 int ans = 0;
		 while (cur.size() != 0)
		 {
			 vector<TreeNode*> cur_copy;
			 cur.swap(cur_copy);
			 for (auto x : cur_copy) {
				 if (x == NULL)  continue;
				 cur.push_back(x->left);
				 cur.push_back(x->right);
			 }
			 if (cur.size() != 0) ans++;
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
	cout << s.maxDepth(root) << endl;
	

	std::cin.get();
}
