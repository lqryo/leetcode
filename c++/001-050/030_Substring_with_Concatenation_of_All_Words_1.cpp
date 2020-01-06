//参考:https://www.cnblogs.com/andingding-blog/p/9055364.html
// 此解法超出时间限制

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words);
};

vector<int> Solution::findSubstring(string s, vector<string>& words)
{
	vector<int> ans = {};
	//先考虑特殊情况
	if (words.size() == 0)
		return ans;

	int word_len = words[0].length();  //单个单词的长度
	int word_num = words.size(); //单词个数
	int substr_len = word_len * word_num; //每次取s子串的长度
	int s_len = s.length();

	 //对words进行排序
	sort(words.begin(), words.end());


	/*对s循环进行切割*/
	int index = 0;  //切割的起始点

	while (index + substr_len <= s_len)
	{
		vector<string> s_substrs;
		for (size_t i = 0; i < word_num; i++)
		{
			s_substrs.push_back(s.substr(index + word_len * i, word_len));
		}

		sort(s_substrs.begin(), s_substrs.end());

		if (s_substrs == words)
		{
			ans.push_back(index);
		}
		index++;
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

	getchar();

	return 0;
}