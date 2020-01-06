#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 参考：https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/bu-tong-de-er-cha-sou-suo-shu-ii-by-leetcode/


 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


 // 卡特兰数

 class Solution {
 public:
	 vector<TreeNode*> generateTrees(int n) {
		 if (n == 0) {
			 return vector<TreeNode*>();
		 }
		 else {
			 return generate_trees(1, n);
		 }
	 }

 private:
	 
	 vector<TreeNode*> generate_trees(int start, int end)
	 {
		 vector<TreeNode*> all_trees;
		 if (start > end) {
			 all_trees.push_back(NULL);
			 return all_trees;
		 }

		 //pick up a root
		 for (size_t i = start; i <= end; i++)
		 {
			 // all possible left subtrees if i is choosen ot be a root
			 vector<TreeNode*> left_trees = generate_trees(start, i - 1);
			 vector<TreeNode*> right_trees = generate_trees(i+1, end);

			 // connect left and right trees to the root i
			 for (auto l_tree : left_trees)
			 {
				 for (auto r_tree : right_trees)
				 {
					 TreeNode* cur_node = new TreeNode(i);
					 cur_node->left = l_tree;
					 cur_node->right = r_tree;
					 all_trees.push_back(cur_node);
				 }
			 }
		 }
		 return all_trees;
	 }

 };





int main()
{
	Solution s;


	std::cin.get();
}
