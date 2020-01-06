//�ο�:https://www.cnblogs.com/andingding-blog/p/9055364.html
// �˽ⷨ����ʱ������

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
	//�ȿ����������
	if (words.size() == 0)
		return ans;

	int word_len = words[0].length();  //�������ʵĳ���
	int word_num = words.size(); //���ʸ���
	int substr_len = word_len * word_num; //ÿ��ȡs�Ӵ��ĳ���
	int s_len = s.length();

	 //��words��������
	sort(words.begin(), words.end());


	/*��sѭ�������и�*/
	int index = 0;  //�и����ʼ��

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