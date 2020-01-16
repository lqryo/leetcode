
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

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
	int countNodes(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int left = countLevel(root->left);
		int right = countLevel(root->right);
		if (left == right) {
			return countNodes(root->right) + (1 << left);
		}
		else {
			return countNodes(root->left) + (1 << right);
		}
	}

private:
	int countLevel(TreeNode* root) {
		int level = 0;
		while (root!=NULL)
		{
			level++;
			root = root->left;
		}
		return level;
	}
};

int main()
{
	Solution s;

	cin.get();

	return 0;
}

