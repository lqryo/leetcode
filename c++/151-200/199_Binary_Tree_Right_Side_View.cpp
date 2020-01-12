
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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ans;
		if (root == NULL) return ans;

		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			ans.push_back(q.front()->val);
			while (size--) {
				TreeNode* tmp = q.front();
				q.pop();
				if (tmp->right) q.push(tmp->right);
				if (tmp->left) q.push(tmp->left);
			}
		}
		return ans;
	}
};


int main()
{
	Solution s;

	cin.get();

	return 0;
}

