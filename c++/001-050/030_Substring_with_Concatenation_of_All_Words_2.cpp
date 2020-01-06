//参考:https://www.cnblogs.com/andingding-blog/p/9055364.html
//用hashmap来优化前一种算法

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words);
};

vector<int> Solution::findSubstring(string s, vector<string>& words)
{
	vector<int> ans = {};
	int word_num = words.size();
	if (word_num == 0) {
		return ans;
	}
	int word_len = words[0].length();
	int substr_len = word_len * word_num;
	//HashMap1 存所有单词
	unordered_map<string, int> hashmap1; //存所有单词
	for (string s : words)
	{
		if (hashmap1.count(s) == 0)
		{
			hashmap1[s] = 1;
		}
		else {
			int value = hashmap1[s];
			hashmap1[s] = value + 1;
		}
	}

	//遍历所有子串
	for (size_t i = 0; i+ substr_len <= s.length(); i++)
	{
		//HashMap2存当前扫描的字串含有的单词
		unordered_map<string, int> hashmap2;
		int num = 0;
		while (num < word_num)
		{
			string word = s.substr(i + num * word_len, word_len);
			//判断该单词在Hashmap1中
			if (hashmap1.count(word) == 1)
			{
				int value = hashmap2[word];
				hashmap2[word] = value + 1;

				//判断当前单词的value和hashmap1中单词的value
				if (hashmap2[word] > hashmap1[word]) { break; }
			}
			else { break; }
			num++;
		}
		//判断是不是所有单词都符合条件
		if (num == word_num) {
			ans.push_back(i);
		}
	}
	return ans;

}


int main(int argc,char* argv[])
{

	Solution solution;
	string s = "barfoothefoobarman";
	vector<string> words{ "foo","bar" };
	vector<int> ans = solution.findSubstring(s, words);

	for (vector<int>::iterator it=ans.begin();it != ans.end();it++ )
	{
		cout << *it << endl;
	}
	cout << "end " << endl;
	getchar();

	return 0;
}