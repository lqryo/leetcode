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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return isMirror(root->left, root->right);
	}
private:
	bool isMirror(TreeNode* t1, TreeNode* t2)
	{
		if (t1 == NULL && t2 == NULL) return true;
		if (t1 == NULL || t2 == NULL) return false;
		return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
	}

};




int main(int argc, char* argv[])
{

	

	std::cin.get();
}
