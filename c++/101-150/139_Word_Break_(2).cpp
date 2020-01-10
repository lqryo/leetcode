#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>


using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};



// 动态规划

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;

		for (size_t i = 0; i < s.size(); i++)
		{
			for (auto x : wordDict)
			{
				int len = x.size();
				if (s.substr(i, len) == x && dp[i] == true) {
					dp[i + len] = true;
				}


			}
		}

		return dp[s.size()];
	}

};



int main()
{
	Solution s;
	vector<string> wordDict{ "apple","pen" };

	cout << s.wordBreak("applepenapple", wordDict) << endl;


	cin.get();
}

