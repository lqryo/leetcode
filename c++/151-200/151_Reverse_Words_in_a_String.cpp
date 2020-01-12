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
#include <stack>


using namespace std;


class Solution {
public:
	string reverseWords(string s) {
		istringstream wordstring(s);
		string word;
		vector<string> words;
		while (getline(wordstring,word,' '))
		{
			if (word.empty()) continue;
			words.push_back(word);
		}

		string ans;
		reverse(words.begin(), words.end());
		for (auto x : words) {
			ans = ans + x + " ";
		}
		ans.pop_back();
		return ans;
	}
};



int main()
{
	Solution s;




	cin.get();
}
