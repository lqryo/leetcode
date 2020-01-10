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




class Solution {
public:
	// 超出时间限制
	bool wordBreak(string s, vector<string>& wordDict) {
		this->s = s;
		this->wordDict = wordDict;
		backTrack(0);
		return flag;
	}
private:
	string s;
	vector<string> wordDict;
	bool flag = false;
	void backTrack(int start)
	{
		if (start >= s.size()) { flag = true; }
		for (auto x : wordDict) {
			int len = x.size();
			if (x == s.substr(start, len))
				backTrack(start + len);
		}
	}

};



int main()
{
	Solution s;
	vector<string> wordDict{ "abbcbda", "cbdaaa", "b", "dadaaad", "dccbbbc", "dccadd", "ccbdbc", "bbca", "bacbcdd", "a", "bacb", "cbc", "adc", "c", "cbdbcad", "cdbab", "db", "abbcdbd", "bcb", "bbdab", "aa", "bcadb", "bacbcb", "ca", "dbdabdb", "ccd", "acbb", "bdc", "acbccd", "d", "cccdcda", "dcbd", "cbccacd", "ac", "cca", "aaddc", "dccac", "ccdc", "bbbbcda", "ba", "adbcadb", "dca", "abd", "bdbb", "ddadbad", "badb", "ab", "aaaaa", "acba", "abbb" };

	cout << s.wordBreak("acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb", wordDict) << endl;


	cin.get();
}

