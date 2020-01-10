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


class Solution {
public:
	// 回溯
	vector<vector<string>> partition(string s) {
		this->s = s;
		vector<string> cur;
		backTrack(0, cur);
		return ans;
	}

private:
	vector<vector<string>> ans;
	string s;
	bool isPalindrome(string s) {
		string s1 = s;
		reverse(s1.begin(), s1.end());

		return s == s1;
	}

	void backTrack(int start,vector<string>& cur)
	{
		if (start >= s.size()) {
			ans.push_back(cur);
			return;
		}
		else {
			for (size_t i = start; i < s.size(); i++)
			{
				string tmp = s.substr(start, i - start + 1);
				if (!isPalindrome(tmp)) continue;
				else {
					cur.push_back(tmp);
					backTrack(i + 1, cur);
					cur.pop_back();
				}
			}
		}
	}
};



int main(int argc, char* argv[])
{
	Solution S;
	S.partition("aab");
	std::cin.get();
}
