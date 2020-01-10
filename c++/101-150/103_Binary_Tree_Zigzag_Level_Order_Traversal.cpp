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
	 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		 if (root == NULL) return ans;
		 vector<TreeNode*> curLevel;
		 curLevel.push_back(root);
		 while (curLevel.size() != 0)
		 {
			 vector<int> tmp;
			 if (left2right) {
				 for (auto it = curLevel.begin(); it != curLevel.end(); ++it) {
					 if (*it == NULL) continue;
					 else tmp.push_back((*it)->val);
				 }
			 }
			 else {
				 for (auto it = curLevel.rbegin(); it != curLevel.rend(); ++it) {
					 if (*it == NULL) continue;
					 else tmp.push_back((*it)->val);
				 }
			 }
			 
			 if (tmp.size() != 0) ans.push_back(tmp);

			 vector<TreeNode*> curLevel_copy;
			 curLevel.swap(curLevel_copy);

			 for (auto x : curLevel_copy) {
				if (x == NULL) continue;
				curLevel.push_back(x->left);
				curLevel.push_back(x->right);
			}
			 left2right = !left2right;
		 }
		 return ans;
	 }
 private:
	 vector<vector<int>> ans;
	 bool left2right = true;
 };




int main(int argc, char* argv[])
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution s;
	vector<vector<int>> ans = s.zigzagLevelOrder(root);
	

	std::cin.get();
}
