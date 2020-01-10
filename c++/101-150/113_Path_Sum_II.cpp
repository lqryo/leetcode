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
	 vector<vector<int>> pathSum(TreeNode* root, int sum) {
		 vector<int> path;
		 if (root == NULL) return ans;
		 backTrack(root, path, sum);
		 return ans;
	 }
 private:
	 vector<vector<int>> ans;
	 // int sum;

	 void backTrack(TreeNode* root, vector<int>& path, int sum)
	 {
		 if (root == NULL) return;

		 sum -= root->val;
		 path.push_back(root->val);
		 if (root->left == NULL && root->right == NULL) { //叶子节点
			 if (sum == 0) ans.push_back(path);
			 path.pop_back();
			 return;
		 }

		 backTrack(root->left, path, sum);
		 backTrack(root->right, path, sum);
		 path.pop_back();
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
	vector<vector<int>> ans = s.pathSum(root, 12);

	std::cin.get();
}
